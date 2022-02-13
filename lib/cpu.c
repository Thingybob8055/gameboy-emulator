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
static void fetch_data(){
    ctx.dest_is_mem = false;
    ctx.mem_dest = 0;

    if (ctx.curr_inst == NULL){
        return;
    }

    switch(ctx.curr_inst -> mode){ //switch the current instruction based on addressing mode.
        case AM_IMP: return; //nothing to be read to immediately return

        case AM_R:
            ctx.fetch_data = cpu_read_reg(ctx.curr_inst->reg_1); //fetch data from register
            return;

        case AM_R_D8:
          ctx.fetch_data = bus_read(ctx.regs.program_counter); //take 8 bit value to store in register
          emu_cycles(1); //1 is a placeholder. Like 1 cycle in emulator for reading a bus
          ctx.regs.program_counter++; //increment the program counter.
          return;

        case AM_D16: { //remember: we can only read 8 bits at a time
            u16 lo = bus_read(ctx.regs.program_counter); //reading the low value
            emu_cycles(1);

            u16 hi = bus_read(ctx.regs.program_counter + 1); //read the high value
            emu_cycles(1);

            ctx.fetch_data = lo | (hi << 8); //lo binary or with hi shifted 8

            ctx.regs.program_counter += 2; //increment program counter twice

            return;
        }
        default:
            printf("Not yet implemented addressing mode: %d\n", ctx.curr_inst -> mode);
            exit(-200);
            return;

    }

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
        printf("Received Instruction: %02X   PC: %04X\n", ctx.current_opcode, program_counter);

        if (ctx.curr_inst == NULL){
            printf("[!]UNKNOWN INSTRUCTION! %02X\n", ctx.current_opcode);
            exit(-7);
        }
        
        execute();
    }
    return true;
}
