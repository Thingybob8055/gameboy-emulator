#include <cpu.h>
#include <bus.h>
#include <emu.h>

cpu_context ctx = {0}; //initialise all to 0

void cpu_init() {
    ctx.regs.program_counter = 0x100;
    ctx.regs.a = 0x01;
}

static void fetch_instruction(){
    ctx.current_opcode = bus_read(ctx.regs.program_counter++); //we read from the bus using the program counter register
    ctx.curr_inst = instruction_by_opcode(ctx.current_opcode);

    // if (ctx.curr_inst == NULL){
    //     printf("[!]UNKNOWN INSTRUCTION! %02X\n", ctx.current_opcode);
    //     exit(-7);
    // }
}

static void execute(){
    //printf("[!]NOT YET IMPLEMENTED EXECUTION...........\n");
    //A function pointer
    //we pass in the current instructions type
    IN_PROC proc = inst_get_processor(ctx.curr_inst->type);
    //this gives us back a function pointer or 0

    if(!proc){
        NO_IMPL
    }

    //if we found the function, we need to execute that function
    proc(&ctx);

}


bool cpu_step(){
    
    if(!ctx.halted){ //what happens in the cpu step when CPU is not halted.
        u16 program_counter = ctx.regs.program_counter;
        fetch_instruction();
        fetch_data();

        //for logging
        printf("%04X: %-7s (%02X %02X %02X) A: %02X B: %02X C: %02X\n", 
            program_counter, inst_name(ctx.curr_inst->type), ctx.current_opcode,
            bus_read(program_counter + 1), bus_read(program_counter + 2), ctx.regs.a, ctx.regs.b, ctx.regs.c);

        //printf("Received Instruction: %02X   PC: %04X\n", ctx.current_opcode, program_counter);

        if (ctx.curr_inst == NULL){
            printf("[!]UNKNOWN INSTRUCTION! %02X\n", ctx.current_opcode);
            exit(-7);
        }
        
        execute();
    }
    return true;
}
