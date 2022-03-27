#include <cpu.h>
#include <emu.h>
#include <bus.h>

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

static void proc_jp(cpu_context *ctx){
    if (check_cond(ctx)) {
        //if check passes, we set the program counter to value of fetctched data
        ctx->regs.program_counter = ctx->fetch_data;
        emu_cycles(1); //doing a jump requires CPU cycles
        //we need to synchronise the PPU and timer
    }
}

// array of function pointers that will process instructions
//kinda like a hash map
//IN_PROC is made a function pointer so that it can point to these function to proccess the instruction
IN_PROC processors[] = {
    [IN_NONE] = proc_none,
    [IN_NOP] = proc_nop,
    [IN_LD] = proc_ld,
    [IN_JP] = proc_jp,
    [IN_DI] = proc_di,
    [IN_XOR] = proc_xor
};

IN_PROC inst_get_processor(in_type type){
    return processors[type];
}