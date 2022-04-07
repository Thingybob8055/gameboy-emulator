#include <cpu.h>
#include <stack.h>
#include <interrupts.h>

//internal function to handle interrupts. Give cpu context and given address
void int_handle(cpu_context *ctx, u16 address) {
    stack_push16(ctx->regs.pc); //push current address onto stack
    ctx->regs.pc = address; //our interrupt factor
}

bool int_check(cpu_context *ctx, u16 address, interrupt_type it) {
    //if interrupt is waiting to be processed
    if (ctx->int_flags & it && ctx->ie_register & it) {
        int_handle(ctx, address);
        ctx->int_flags &= ~it;
        ctx->halted = false;
        ctx->int_master_enabled = false;

        return true;
    }

    return false;
}

void cpu_handle_interrupts(cpu_context *ctx) {
    //sends specific address of each interrupt type
    if (int_check(ctx, 0x40, IT_VBLANK)) {

    } else if (int_check(ctx, 0x48, IT_LCD_STAT)) {

    } else if (int_check(ctx, 0x50, IT_TIMER)) {

    }  else if (int_check(ctx, 0x58, IT_SERIAL)) {

    }  else if (int_check(ctx, 0x60, IT_JOYPAD)) {

    } 
}

