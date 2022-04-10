#include <ppu.h>
#include <lcd.h>
#include <cpu.h>
#include <interrupts.h>

void increment_ly() {
    lcd_get_context()->ly++;

    if (lcd_get_context()->ly == lcd_get_context()->ly_compare) {
        LCDS_LYC_SET(1);

        if (LCDS_STAT_INT(SS_LYC)) {
            //throw interrupt if set
            cpu_request_interrupt(IT_LCD_STAT);
        }
    }
    else {
        LCDS_LYC_SET(0);
    }
}

void ppu_mode_oam() {
    if (ppu_get_context()->line_ticks >= 80) {
        LCDS_MODE_SET(MODE_XFER); ///switch mode to XFER
    }
}

void ppu_mode_xfer() {
    if (ppu_get_context()->line_ticks >= 80 + 172) {
        LCDS_MODE_SET(MODE_HBLANK); //switch to next mode
    }
}

void ppu_mode_vblank() {
    if (ppu_get_context()->line_ticks >= TICKS_PER_LINE) {
        increment_ly(); //increment as we are moving to a new line

        if (lcd_get_context()->ly >= LINES_PER_FRAME) {
            LCDS_MODE_SET(MODE_OAM); //go back to beginning
            lcd_get_context()->ly = 0; //thus, reset ly
        }

        ppu_get_context()->line_ticks = 0; //reset as we go to a new line
    }
}

static u32 target_frame_time = 1000 / 60; //60 FPS (1000ms in 1 sec)
static long prev_frame_time = 0;
static long start_timer = 0;
static long frame_count = 0;

void ppu_mode_hblank() {
    if (ppu_get_context()->line_ticks >= TICKS_PER_LINE) {
        increment_ly();

        if (lcd_get_context()->ly >= YRES) {
            LCDS_MODE_SET(MODE_VBLANK);

            cpu_request_interrupt(IT_VBLANK);

            if (LCDS_STAT_INT(SS_VBLANK)) {
                cpu_request_interrupt(IT_LCD_STAT);
            }

            ppu_get_context()->current_frame++;

            //calcylate the  FPS
            u32 end = get_ticks(); //no of ms ticks since program started
            u32 frame_time = end - prev_frame_time;

            if (frame_time < target_frame_time) {
                delay((target_frame_time - frame_time)); //delay that many ms to acheive 60fps
            }

            if (end - start_timer >= 1000) {
                u32 fps = frame_count;
                start_timer = end;
                frame_count = 0;

                printf("[!]FPS: %d\n", fps);
            }

            frame_count++;
            prev_frame_time = get_ticks();

        }
        else {
            LCDS_MODE_SET(MODE_OAM); //go back to begenning
        }

        ppu_get_context()->line_ticks = 0;
    }
}