#include <cpu.h>
#include <bus.h>
#include <emu.h>

cpu_context ctx = {0}; //initialise all to 0

void cpu_init() {
    ctx.regs.program_counter = 0x100;
    ctx.regs.a = 0x01;
}

static void fetch_instruction() {
    ctx.current_opcode = bus_read(ctx.regs.program_counter++); //we read from the bus using the program counter register
    ctx.curr_inst = instruction_by_opcode(ctx.current_opcode);

    // if (ctx.curr_inst == NULL){
    //     printf("[!]UNKNOWN INSTRUCTION! %02X\n", ctx.current_opcode);
    //     exit(-7);
    // }
}

void fetch_data();

static void execute() {
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

bool cpu_step() {
    
    if(!ctx.halted){ //what happens in the cpu step when CPU is not halted.
        u16 program_counter = ctx.regs.program_counter;
        fetch_instruction();
        emu_cycles(1);
        fetch_data();

        //for logging
        // printf("%04X: %-7s (%02X %02X %02X) A: %02X B: %02X C: %02X\n", 
        //     program_counter, inst_name(ctx.curr_inst->type), ctx.current_opcode,
        //     bus_read(program_counter + 1), bus_read(program_counter + 2), ctx.regs.a, ctx.regs.b, ctx.regs.c);

        char flags[16];
        sprintf(flags, "%c%c%c%c", 
            ctx.regs.f & (1 << 7) ? 'Z' : '-',
            ctx.regs.f & (1 << 6) ? 'N' : '-',
            ctx.regs.f & (1 << 5) ? 'H' : '-',
            ctx.regs.f & (1 << 4) ? 'C' : '-'
        );

        printf("%08lX - %04X: %-7s (%02X %02X %02X) A: %02X F: %s BC: %02X%02X DE: %02X%02X HL: %02X%02X\n", 
            emu_get_context()->ticks,
            program_counter, inst_name(ctx.curr_inst->type), ctx.current_opcode,
            bus_read(program_counter + 1), bus_read(program_counter + 2), ctx.regs.a, flags, ctx.regs.b, ctx.regs.c,
            ctx.regs.d, ctx.regs.e, ctx.regs.h, ctx.regs.l);

        //printf("Received Instruction: %02X   PC: %04X\n", ctx.current_opcode, program_counter);

        if (ctx.curr_inst == NULL) {
            printf("[!]UNKNOWN INSTRUCTION! %02X\n", ctx.current_opcode);
            exit(-7);
        }
        
        execute();
    }
    return true;
}

u8 cpu_get_ie_register() {
    return ctx.ie_register;
}

void cpu_set_ie_register(u8 n) {
    ctx.ie_register = n;
}