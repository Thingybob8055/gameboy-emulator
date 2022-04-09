#include <dma.h>
#include <ppu.h>
#include <bus.h>

typedef struct {
    bool active; //if dma transfer is active
    u8 byte; //current byte
    u8 value; //the value
    u8 start_delay; //there is a start delay
}dma_context;

static dma_context ctx;

void dma_start(u8 start) {
    ctx.active = true;
    ctx.byte = 0;
    ctx.start_delay = 2;
    ctx.value = start;
}

void dma_tick() {
    if (!ctx.active) {
        return; //return is dma is not active
    }

    if (ctx.start_delay) {
        ctx.start_delay--;
        return; //decrement and return. at 0, we can do dma writing
    }

    //transfer the bytes
    ppu_oam_write(ctx.byte, bus_read((ctx.value * 0x100) + ctx.byte));

    ctx.byte++;

    ctx.active = ctx.byte < 0xA0; //tells us if its done, if reached this byte

    if (!ctx.active) {
        printf("DMA DONE!\n");
        sleep(2);
    }
}

bool dma_transferring() {
    return ctx.active;
}