#include <cpu.h>
#include <emu.h>

//This will process CPU instructions

//parameter is a cpu_context pointer
static void proc_none(cpu_context *ctx){
    printf("[!]INVALID INSTRUCTION\n");
    exit(-200);
}

static void proc_ld(cpu_context *ctx){

}

static void proc_nop(cpu_context *ctx){
    //does nothing
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
};

IN_PROC inst_get_processor(in_type type){
    return processors[type];
}