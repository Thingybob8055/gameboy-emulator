#include <cpu.h>

static cpu_context ctx;

void fetch_data(){
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

        case AM_R_R: //fetch data for 2nd register
            ctx.fetch_data = cpu_read_reg(ctx.curr_inst->reg_2); //fetch data from register
            return;

        case AM_R_D8:
          ctx.fetch_data = bus_read(ctx.regs.program_counter); //take 8 bit value to store in register
          emu_cycles(1); //1 is a placeholder. Like 1 cycle in emulator for reading a bus
          ctx.regs.program_counter++; //increment the program counter.
          return;

        //16 bit number and register
        case AM_R_D16:
        case AM_D16: { //remember: we can only read 8 bits at a time
            u16 lo = bus_read(ctx.regs.program_counter); //reading the low value
            emu_cycles(1);

            u16 hi = bus_read(ctx.regs.program_counter + 1); //read the high value
            emu_cycles(1);

            ctx.fetch_data = lo | (hi << 8); //lo binary or with hi shifted 8

            ctx.regs.program_counter += 2; //increment program counter twice

            return;
        }

        //load register to memory region
        case AM_MR_R:
            

        default:
            printf("Not yet implemented addressing mode: %d\n", ctx.curr_inst -> mode);
            exit(-200);
            return;

    }

}