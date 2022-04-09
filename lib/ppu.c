#include <ppu.h>

static ppu_context ctx;

void ppu_init() {

}

void ppu_tick() {

}

//OAM read and write may be accessed through the DMA (Direct Memory Access). Which won't use the offset. Hence the conditional statement is needed unlike the vram
void ppu_oam_write(u16 address, u8 value) {
    if(address >= 0xFE00){
        address -= 0xFE00; //decrease as when we are using the buffer, we are usig the offset
    }

    u8 *p = (u8 *)ctx.oam_ram; //a byte array
    p[address] = value; 
}

u8 ppu_oam_read(u16 address) {
    if(address >= 0xFE00){
        address -= 0xFE00; //decrease as when we are using the buffer, we are usig the offset
    }

    u8 *p = (u8 *)ctx.oam_ram;
    return p[address];

}

void ppu_vram_write(u16 address, u8 value) {
    ctx.vram[address - 0x8000] = value;
}

u8 ppu_vram_read(u16 address) {
    return ctx.vram[address - 0x8000];
}