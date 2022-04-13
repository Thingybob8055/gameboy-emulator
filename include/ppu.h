#pragma once

#include <common.h>

static const int LINES_PER_FRAME = 154;
static const int TICKS_PER_LINE = 456;
static const int YRES = 144;
static const int XRES = 160;

typedef enum {
    FS_TILE,
    FS_DATA0,
    FS_DATA1,
    FS_IDLE,
    FS_PUSH
}fetch_state;

typedef struct _fifo_entry {
    struct _fifo_entry *next; //next entry pointer
    u32 value; //32 bit color value,colour of pixel
}fifo_entry;

//information about the fifo
typedef struct {
    fifo_entry *head;
    fifo_entry *tail;
    u32 size;
}fifo;

typedef struct {
    fetch_state cur_fetch_state; //grab state of FIFO
    fifo pixel_fifo;
    u8 line_x;
    u8 pushed_x;
    u8 fetch_x;
    u8 bgw_fetch_data[3];
    u8 fetch_entry_data[6]; //OAM data
    u8 map_y;
    u8 map_x;
    u8 tile_y;
    u8 fifo_x;
}pixel_fifo_context; //internal state of the FIFO

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

//another linked list style
typedef struct _oam_line_entry {
    oam_entry entry;
    struct _oam_line_entry *next;
}oam_line_entry;

typedef struct {
    oam_entry oam_ram[40]; //oam ram has 40 of these oam entries
    u8 vram[0x2000]; //video ram is 0x2000 bytes

    pixel_fifo_context pfc; 

    u8 line_sprite_count; //0 to 10 sprites max per line
    oam_line_entry *line_sprites; //linked list of current sprites on line
    oam_line_entry line_entry_array[10]; //for the memory of our linked list (so that malloc and free isn't used all the time)

    u8 fetched_entry_count; //FIFO fetching process
    oam_entry fetched_entries[3]; //entries fetched during pipline
    u8 window_line;

    u32 current_frame;
    u32 line_ticks; //how many ticks in line currently
    u32 *video_buffer; //where we draw pixels
} ppu_context;


void ppu_init();
void ppu_tick();

//these are done through the bus
void ppu_oam_write(u16 address, u8 value); //for the oam
u8 ppu_oam_read(u16 address);

void ppu_vram_write(u16 address, u8 value); //for the vram
u8 ppu_vram_read(u16 address);

ppu_context *ppu_get_context();