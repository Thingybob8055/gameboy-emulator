#include <ppu.h>
#include <lcd.h>
#include <string.h>
#include <ppu_sm.h>

static ppu_context ctx;

//to allow other components to use the PPU
ppu_context *ppu_get_context() {
    return &ctx;
}

void ppu_init() {
    ctx.current_frame = 0;
    ctx.line_ticks = 0;
    //allocate memory for video buffer
    ctx.video_buffer = malloc(YRES * XRES * sizeof(32));

    lcd_init();
    LCDS_MODE_SET(MODE_OAM); //starting mode/state

    //zero all oam_ram and video_buffer
    memset(ctx.oam_ram, 0, sizeof(ctx.oam_ram));
    memset(ctx.video_buffer, 0, YRES * XRES * sizeof(u32));
}

void ppu_tick() {
     ctx.line_ticks++; //increment line for every tick

    switch(LCDS_MODE) {
    case MODE_OAM:
        ppu_mode_oam();
        break;
    case MODE_XFER:
        ppu_mode_xfer();
        break;
    case MODE_VBLANK:
        ppu_mode_vblank();
        break;
    case MODE_HBLANK:
        ppu_mode_hblank();
        break;
    }
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