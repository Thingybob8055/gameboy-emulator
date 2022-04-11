#include <ppu.h>
#include <lcd.h>
#include <bus.h>

//pushes pixel to the FIFO
void pixel_fifo_push(u32 value) {
    fifo_entry *next = malloc(sizeof(fifo_entry));
    next->next = NULL;
    next->value = value;
    //above, typical linked list style entry
    
    if (!ppu_get_context()->pfc.pixel_fifo.head) {
        //first entry if not set 
        ppu_get_context()->pfc.pixel_fifo.head = ppu_get_context()->pfc.pixel_fifo.tail = next;
    } else {
        ppu_get_context()->pfc.pixel_fifo.tail->next = next;
        ppu_get_context()->pfc.pixel_fifo.tail = next;
    }

    ppu_get_context()->pfc.pixel_fifo.size++;
}

//takes element off the FIFO
u32 pixel_fifo_pop() {
    //If there is nothing in the FIFO and size is <- 0
    if (ppu_get_context()->pfc.pixel_fifo.size <= 0) {
        fprintf(stderr, "ERR IN PIXEL FIFO!\n");
        exit(-8);
    }

    fifo_entry *popped = ppu_get_context()->pfc.pixel_fifo.head;
    ppu_get_context()->pfc.pixel_fifo.head = popped->next;
    ppu_get_context()->pfc.pixel_fifo.size--;

    u32 val = popped->value;
    free(popped);

    return val;
}

bool pipeline_fifo_add() {
    if (ppu_get_context()->pfc.pixel_fifo.size > 8) {
        //fifo is full so we can't add. Allows us to stay in push state until FIFO is not full so we don't push the fixels
        return false;
    }

    int x = ppu_get_context()->pfc.fetch_x - (8 - (lcd_get_context()->scroll_x % 8));

    //loop through the bits
    for (int i=0; i<8; i++) {
        int bit = 7 - i;
        //similar to how it is done on the debug window
        u8 hi = !!(ppu_get_context()->pfc.bgw_fetch_data[1] & (1 << bit));
        u8 lo = !!(ppu_get_context()->pfc.bgw_fetch_data[2] & (1 << bit)) << 1;
        u32 color = lcd_get_context()->bg_colors[hi | lo];

        if (x >= 0) {
            pixel_fifo_push(color); //push the colour to the FIFO
            ppu_get_context()->pfc.fifo_x++; //increment the FIFO x
        }
    }

    return true; //let the other function know to move to the start state
}

void pipeline_fetch() {
    switch(ppu_get_context()->pfc.cur_fetch_state) {
        case FS_TILE: {
            if (LCDC_BGW_ENABLE) {
                ppu_get_context()->pfc.bgw_fetch_data[0] = bus_read(LCDC_BG_MAP_AREA + 
                    (ppu_get_context()->pfc.map_x / 8) + 
                    (((ppu_get_context()->pfc.map_y / 8)) * 32));
            
                if (LCDC_BGW_DATA_AREA == 0x8800) {
                    ppu_get_context()->pfc.bgw_fetch_data[0] += 128;
                }
            }

            ppu_get_context()->pfc.cur_fetch_state = FS_DATA0;
            ppu_get_context()->pfc.fetch_x += 8;
        } break;

        case FS_DATA0: {
            ppu_get_context()->pfc.bgw_fetch_data[1] = bus_read(LCDC_BGW_DATA_AREA +
                (ppu_get_context()->pfc.bgw_fetch_data[0] * 16) + 
                ppu_get_context()->pfc.tile_y);

            ppu_get_context()->pfc.cur_fetch_state = FS_DATA1;
        } break;

        case FS_DATA1: {
            ppu_get_context()->pfc.bgw_fetch_data[2] = bus_read(LCDC_BGW_DATA_AREA +
                (ppu_get_context()->pfc.bgw_fetch_data[0] * 16) + 
                ppu_get_context()->pfc.tile_y + 1);

            ppu_get_context()->pfc.cur_fetch_state = FS_IDLE;

        } break;

        case FS_IDLE: {
            ppu_get_context()->pfc.cur_fetch_state = FS_PUSH;
        } break;

        case FS_PUSH: {
            if (pipeline_fifo_add()) {
                ppu_get_context()->pfc.cur_fetch_state = FS_TILE;
            }

        } break;

    }
}

//pushes the pixel on to the pipeline
void pipeline_push_pixel() {
    //FIFO is full, so we can start pushing the pixels
    if (ppu_get_context()->pfc.pixel_fifo.size > 8) {
        u32 pixel_data = pixel_fifo_pop(); //pop a pixel off the fifo

        if (ppu_get_context()->pfc.line_x >= (lcd_get_context()->scroll_x % 8)) {
            ppu_get_context()->video_buffer[ppu_get_context()->pfc.pushed_x + 
                (lcd_get_context()->ly * XRES)] = pixel_data; //put to the video buffer

            ppu_get_context()->pfc.pushed_x++; //pushed a value hence increment
        }

        ppu_get_context()->pfc.line_x++; //increment the line
    }
}

void pipeline_process() {
    //Get the current map data
    ppu_get_context()->pfc.map_y = (lcd_get_context()->ly + lcd_get_context()->scroll_y);
    ppu_get_context()->pfc.map_x = (ppu_get_context()->pfc.fetch_x + lcd_get_context()->scroll_x);
    ppu_get_context()->pfc.tile_y = ((lcd_get_context()->ly + lcd_get_context()->scroll_y) % 8) * 2;

    //check the first bit of of line ticks
    //if not set, we are on an even line
    if (!(ppu_get_context()->line_ticks & 1)) {
        pipeline_fetch();
    }

    pipeline_push_pixel(); //happens every tick
}

//when done with FIFO, you need to reset it
void pipeline_fifo_reset() {
    //pop and free from memory if size > 0
    while(ppu_get_context()->pfc.pixel_fifo.size) {
        pixel_fifo_pop();
    }

    ppu_get_context()->pfc.pixel_fifo.head = 0;
}