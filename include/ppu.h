#pragma once

#include <common.h>

typedef struct {
    u8 y;
    u8 x;
    u8 tile;
    
    //top two are for colour gb only
    unsigned f_cgb_pn : 3; //these are bitmaps with sizes equal to shown in the comment block below
    unsigned f_cgb_vram_bank : 1; //(borrowed from the pandocs)
    unsigned f_pn : 1;
    unsigned f_x_flip : 1; //to flip sprites horizontally ot vertically
    unsigned f_y_flip : 1;
    unsigned f_bgp : 1; //background priority

} oam_entry; //these contain the OAM Attribite flags and info

/*
 Bit7   BG and Window over OBJ (0=No, 1=BG and Window colors 1-3 over the OBJ)
 Bit6   Y flip          (0=Normal, 1=Vertically mirrored)
 Bit5   X flip          (0=Normal, 1=Horizontally mirrored)
 Bit4   Palette number  **Non CGB Mode Only** (0=OBP0, 1=OBP1)
 Bit3   Tile VRAM-Bank  **CGB Mode Only**     (0=Bank 0, 1=Bank 1)
 Bit2-0 Palette number  **CGB Mode Only**     (OBP0-7)
 */

typedef struct {
    oam_entry oam_ram[40]; //oam ram has 40 of these oam entries
    u8 vram[0x2000]; //video ram is 0x2000 bytes
} ppu_context;


void ppu_init();
void ppu_tick();

//these are done through the bus
void ppu_oam_write(u16 address, u8 value); //for the oam
u8 ppu_oam_read(u16 address);

void ppu_vram_write(u16 address, u8 value); //for the vram
u8 ppu_vram_read(u16 address);