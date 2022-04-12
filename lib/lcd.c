#include <lcd.h>
#include <ppu.h>
#include <dma.h>

static lcd_context ctx;

//default colours
static unsigned long colors_default[4] = {0xFFFFFFFF, 0xFFAAAAAA, 0xFF555555, 0xFF000000}; 

void lcd_init() {
    ctx.lcdc = 0x91; //setting some default values
    ctx.scroll_x = 0;
    ctx.scroll_y = 0;
    ctx.ly = 0;
    ctx.ly_compare = 0;
    ctx.bg_palette = 0xFC;
    ctx.obj_palette[0] = 0xFF;
    ctx.obj_palette[1] = 0xFF;
    ctx.win_y = 0;
    ctx.win_x = 0;

    //loop through to set to dafault colours
    for (int i=0; i<4; i++) {
        ctx.bg_colors[i] = colors_default[i];
        ctx.sp1_colors[i] = colors_default[i];
        ctx.sp2_colors[i] = colors_default[i];
    }
}

lcd_context *lcd_get_context() {
    return &ctx;
}

//offset based on starting address.
u8 lcd_read(u16 address) {
    u8 offset = (address - 0xFF40);
    //since all the registers are listed in order, we can convert the context into a byte array based on the starting register (0xFF40), and return the required information
    u8 *p = (u8 *)&ctx;

    return p[offset];
}

//0 pallete = background
//1 and 2 are object palletes
void update_palette(u8 palette_data, u8 pal) {
    u32 *p_colors = ctx.bg_colors;

    switch(pal) {
        case 1:
            p_colors = ctx.sp1_colors;
            break;
        case 2:
            p_colors = ctx.sp2_colors;
            break;
    }

    //comes from the pandocs
    p_colors[0] = colors_default[palette_data & 0b11]; //bottom two bits infer colour 0
    p_colors[1] = colors_default[(palette_data >> 2) & 0b11]; //next 2 bits...
    p_colors[2] = colors_default[(palette_data >> 4) & 0b11];
    p_colors[3] = colors_default[(palette_data >> 6) & 0b11];
}

void lcd_write(u16 address, u8 value) {

    u8 offset = (address - 0xFF40);
    u8 *p = (u8 *)&ctx;
    p[offset] = value;

    if (offset == 6) { 
        //0xFF46 = DMA register
        dma_start(value);
    }

    if (address == 0xFF47) {
        update_palette(value, 0);
    } 
    else if (address == 0xFF48) {
        update_palette(value & 0b11111100, 1);
    } 
     else if (address == 0xFF49) {
        update_palette(value & 0b11111100, 1);
    }
}