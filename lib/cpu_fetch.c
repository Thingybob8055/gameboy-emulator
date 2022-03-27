#include <cpu.h>
#include <bus.h>
#include <emu.h>

extern cpu_context ctx;

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

        //load register to memory region, e.g loading A into the address of BC
        case AM_MR_R:
            ctx.fetch_data = cpu_read_reg(ctx.curr_inst->reg_2); //fetch data from register 2
            ctx.mem_dest = cpu_read_reg(ctx.curr_inst->reg_1); //the destination is a memory location, so we set it to a memory destination
            ctx.dest_is_mem = true;

            //a special case for opcode E2, where we write to C with most significant bit set to FF, as a 16 bit address.
            if(ctx.curr_inst->reg_1 == RT_C){
                ctx.mem_dest |= 0xFF00;
            }

            return;

        case AM_R_MR: { //the oppossite of above
            u16 addr = cpu_read_reg(ctx.curr_inst->reg_2);

            if(ctx.curr_inst->reg_1 == RT_C){
                addr |= 0xFF00;
            }

            ctx.fetch_data = bus_read(addr);
            emu_cycles(1); //increment cpu cycles as we did bus read

        } return;

        case AM_R_HLI: //load address of HL register and increment it
            ctx.fetch_data = bus_read(cpu_read_reg(ctx.curr_inst->reg_2));
            emu_cycles(1);

            cpu_set_reg(RT_HL, cpu_read_reg(RT_HL) + 1); //set value of HL to HL+1

            return;

        case AM_R_HLD: //load address of HL register and decrement it
            ctx.fetch_data = bus_read(cpu_read_reg(ctx.curr_inst->reg_2));
            emu_cycles(1);

            cpu_set_reg(RT_HL, cpu_read_reg(RT_HL) - 1); //set value of HL to HL-1

            return;

        case AM_HLI_R: //moving register value into HL register and incrementing it
           ctx.fetch_data = bus_read(cpu_read_reg(ctx.curr_inst->reg_2)); //read from reg2
           ctx.mem_dest = cpu_read_reg(ctx.curr_inst->reg_1); //mem dest is reg1
           ctx.dest_is_mem = true;
           cpu_set_reg(RT_HL, cpu_read_reg(RT_HL) + 1);
           break;

        case AM_HLD_R: //moving register value into HL register and incrementing it
           ctx.fetch_data = bus_read(cpu_read_reg(ctx.curr_inst->reg_2)); //read from reg2
           ctx.mem_dest = cpu_read_reg(ctx.curr_inst->reg_1); //mem dest is reg1
           ctx.dest_is_mem = true;
           cpu_set_reg(RT_HL, cpu_read_reg(RT_HL) - 1);
           return;
        
        case AM_R_A8:
            ctx.fetch_data = bus_read(ctx.regs.program_counter); //data read from program counter
            emu_cycles(1);
            ctx.regs.program_counter++;
            return;
        
        case AM_A8_R: //oppossite, moving from register to A8
            ctx.mem_dest = bus_read(ctx.regs.program_counter) | 0xFF00;
            ctx.dest_is_mem = true;
            emu_cycles(1);
            ctx.regs.program_counter++;
            return;

        case AM_HL_SPR: //a special case for one instruction, load stack pointer and hl, incremented by r8
            ctx.fetch_data = bus_read(ctx.regs.program_counter); //we get data from program counter
            emu_cycles(1);
            ctx.regs.program_counter++;
            return;

        case AM_D8:
            ctx.fetch_data = bus_read(ctx.regs.program_counter); //we get data from program counter
            emu_cycles(1);
            ctx.regs.program_counter++;
            return;

        //moving a register to a 16 bit address
        case AM_A16_R:
        case AM_D16_R: {
            u16 lo = bus_read(ctx.regs.program_counter); //reading the low value
            emu_cycles(1);

            u16 hi = bus_read(ctx.regs.program_counter + 1); //read the high value
            emu_cycles(1);

            ctx.mem_dest = lo | (hi << 8); //lo binary or with hi shifted 8
            ctx.dest_is_mem = true;

            ctx.regs.program_counter += 2; //increment program counter twice
            ctx.fetch_data = cpu_read_reg(ctx.curr_inst->reg_2);

        } return;

        case AM_MR_D8: //loading D8 into memory address register
            ctx.fetch_data = bus_read(ctx.regs.program_counter);
            emu_cycles(1);
            ctx.regs.program_counter++;
            ctx.mem_dest = cpu_read_reg(ctx.curr_inst->reg_1);
            ctx.dest_is_mem = true;
            return;
        
        case AM_MR: //similar to above but we don't fetch data and read the value from first register
            ctx.mem_dest = cpu_read_reg(ctx.curr_inst->reg_1);
            ctx.dest_is_mem = true;
            ctx.mem_dest = cpu_read_reg(bus_read(ctx.curr_inst->reg_1));
            emu_cycles(1);
            return;

        case AM_R_A16: {
            u16 lo = bus_read(ctx.regs.program_counter); //reading the low value
            emu_cycles(1);

            u16 hi = bus_read(ctx.regs.program_counter + 1); //read the high value
            emu_cycles(1);

            u16 addr = lo | (hi << 8); //lo binary or with hi shifted 8

            ctx.regs.program_counter += 2; //increment program counter twice

            ctx.fetch_data = bus_read(addr); //fetch data is bus read the address
            emu_cycles(1);
        } return;

        default:
            printf("Not yet implemented addressing mode: %d\n", ctx.curr_inst -> mode);
            exit(-200);
            return;

    }

}