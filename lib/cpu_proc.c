#include <cpu.h>
#include <emu.h>
#include <bus.h>
#include <stack.h>

void cpu_set_flags(cpu_context *ctx, char z, char n, char h, char c){
    //sometimes we don't want to modify a flag, this will be set to -1
    if (z != -1){
        BIT_SET(ctx->regs.f, 7, z);
    }

    if (n != -1){
        BIT_SET(ctx->regs.f, 6, n);
    }

    if (h != -1){
        BIT_SET(ctx->regs.f, 5, h);
    }

    if (c != -1){
        BIT_SET(ctx->regs.f, 4, c);
    }

}

//This will process CPU instructions

//parameter is a cpu_context pointer
static void proc_none(cpu_context *ctx){
    printf("[!]INVALID INSTRUCTION\n");
    exit(-200);
}

static void proc_nop(cpu_context *ctx){
    //does nothing
}

static void proc_di(cpu_context *ctx){
    ctx->int_master_enabled = false;
}

static void proc_ld(cpu_context *ctx){
    
    if (ctx->dest_is_mem) { //if destination is memory, LD (BC) A for example
        
        if (ctx->curr_inst->reg_2 >= RT_AF) {  //if 16 bit value from reg_type
            emu_cycles(1);
            bus_write16(ctx->mem_dest, ctx->fetch_data); //16 bit write to the memory destination with value of fetched data
        }
        else {
            bus_write(ctx->mem_dest, ctx->fetch_data);
        }

        return;
    }

    if (ctx->curr_inst->mode == AM_HL_SPR) {
        u8 hflag = (cpu_read_reg(ctx->curr_inst->reg_2) & 0xF) + (ctx->fetch_data & 0xF) > 0x10; //hflag
        u8 cflag = (cpu_read_reg(ctx->curr_inst->reg_2) & 0xFF) + (ctx->fetch_data & 0xFF) > 0x100; //carry flag

        cpu_set_flags(ctx, 0, 0, hflag, cflag);
        cpu_set_reg(ctx->curr_inst->reg_1, cpu_read_reg(ctx->curr_inst->reg_2) + (char)ctx->fetch_data); //casting char as its unsigned

        return;
    }

    cpu_set_reg(ctx->curr_inst->reg_1, ctx->fetch_data);
}

static void proc_ldh(cpu_context *ctx) {
    if (ctx->curr_inst->reg_1 == RT_A) {
        cpu_set_reg(ctx->curr_inst->reg_1, bus_read(0xFF00 | ctx->fetch_data)); //reading from high ram (hram) here
    } 
    else {
        bus_write(0xFF00 | ctx->fetch_data, ctx->regs.a); //oppossite, write to hram with the fetched data or with 0xFF00, grab from regs.a
    }
    
    emu_cycles(1);

}

static void proc_xor(cpu_context *ctx){
    ctx->regs.a ^= ctx->fetch_data & 0xFF; //we only care about the lower byte of the 16 bit data for register A, and hence we do &0xFF

    //the XOR function effects the CPU flags
    cpu_set_flags(ctx, ctx->regs.a, 0, 0, 0);
}

static bool check_cond(cpu_context *ctx){
    bool z = CPU_FLAG_Z;
    bool c = CPU_FLAG_C;

    switch(ctx->curr_inst->cond){
        //no condition means return true as we always jump
        case CT_NONE: return true;
        case CT_C: return c; //only jump is flag c is set
        case CT_NC: return !c; //the reverse of above

        case CT_Z: return z; //only jump is flag z is set
        case CT_NZ: return !z; //the reverse of abobe
    }

    return false;

}


//a jumping function, takes the cpu context, 16 bit address and a boolean flag wether we need to push the program counter.
static void goto_addr(cpu_context *ctx, u16 addr, bool push_programcounter) {
    if (check_cond(ctx)) {
        if (push_programcounter) {
            emu_cycles(2); //2 because its 16 bit address
            stack_push16(ctx->regs.program_counter);
        }

        ctx->regs.program_counter = addr;
        emu_cycles(1); 
    }
}

static void proc_jp(cpu_context *ctx){

    goto_addr(ctx, ctx->fetch_data, false); //false as jp instr does not push the program counter
    // if (check_cond(ctx)) {
    //     //if check passes, we set the program counter to value of fetctched data
    //     ctx->regs.program_counter = ctx->fetch_data;
    //     emu_cycles(1); //doing a jump requires CPU cycles
    //     //we need to synchronise the PPU and timer
    // }
}

//jump relative instruction
static void proc_jr(cpu_context *ctx) {
    char rel = (char)(ctx->fetch_data & 0xFF); //casted char as value can be negative, and we might want to move back a few spaces.
    u16 new_addr = ctx->regs.program_counter + rel; //program counter can go forwards or backwards.
    goto_addr(ctx, new_addr, false);
}

static void proc_call(cpu_context *ctx) {
    goto_addr(ctx, ctx->fetch_data, true); //true as CALL instr does pushes the program counter
}

//This instruction jumps to specific location set by the instruction, and it does also push the program counter
static void proc_rst(cpu_context *ctx) {
    goto_addr(ctx, ctx->curr_inst->param, true); //true as CALL instr does pushes the program counter
}

//returns from the call (basically reverse of call)
static void proc_ret(cpu_context *ctx){
    if (ctx->curr_inst->cond != CT_NONE) {
        emu_cycles(1); //add an emu cycle
    }

    //if condition is met, we need to do the return call
    if (check_cond(ctx)) {
        u16 lo = stack_pop(); //pop first value of the stack
        emu_cycles(1);
        u16 hi = stack_pop();
        emu_cycles(1); //instead of using stack_pop16(), we used 2 8 bit too keep it cycle accurate

        u16 n = (hi <<8) | lo;
        ctx->regs.program_counter = n;
        emu_cycles(1);
    }
}

//similar to proc_ret, but this is returning from an interrupt
static void proc_reti(cpu_context *ctx) {
    ctx->int_master_enabled = true;
    proc_ret(ctx);
}

//POP and PUSH are normally only for 16 bit values
static void proc_pop(cpu_context *ctx) {
    u16 lo = stack_pop();
    emu_cycles(1);
    u16 hi = stack_pop();
    emu_cycles(1);

    u16 n = (hi << 8) | lo;
    cpu_set_reg(ctx->curr_inst->reg_1, n); //set the value of the related register

    //a little differrent behavoir is register is AF
    if (ctx->curr_inst->reg_1 == RT_AF) {
        cpu_set_reg(ctx->curr_inst->reg_1, n & 0xFFF0); //only grab bottom 3 nibbles (one byte + half byte)
    }

}

//pretty much the oppossite of POP
static void proc_push(cpu_context *ctx) {
    u16 hi = (cpu_read_reg(ctx->curr_inst->reg_1) >> 8) & 0xFF;
    emu_cycles(1);
    stack_push(hi);

    u16 lo = (cpu_read_reg(ctx->curr_inst->reg_1)) & 0xFF;
    emu_cycles(1);
    stack_push(lo);

    emu_cycles(1);//emu cycles

}

// array of function pointers that will process instructions
//kinda like a hash map
//IN_PROC is made a function pointer so that it can point to these function to proccess the instruction
IN_PROC processors[] = {
    [IN_NONE] = proc_none,
    [IN_NOP] = proc_nop,
    [IN_LD] = proc_ld,
    [IN_LDH] = proc_ldh,
    [IN_JP] = proc_jp,
    [IN_POP] = proc_pop,
    [IN_PUSH] = proc_push,
    [IN_JR] = proc_jr,
    [IN_CALL] = proc_call,
    [IN_RET] = proc_ret,
    [IN_RST] = proc_rst,
    [IN_RETI] = proc_reti,
    [IN_DI] = proc_di,
    [IN_XOR] = proc_xor
};

IN_PROC inst_get_processor(in_type type){
    return processors[type];
}