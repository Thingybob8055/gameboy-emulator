#include <stdio.h>
#include <emu.h>
#include <cart.h>
#include <cpu.h>
#include <ui.h>
#include <timer.h>
#include <ppu.h>
#include <dma.h>
#ifdef _WIN32
    #include <windows.h>
#else
    #include <pthread.h> //only works in linux
    #include <unistd.h>
#endif

/* 
  Emu components:

  |Cart|
  |CPU|
  |Address Bus|
  |PPU|
  |Timer|

*/

static emu_context ctx;

emu_context *emu_get_context() {
    return &ctx;
}

#ifdef _WIN32
DWORD WINAPI cpu_run(LPVOID lpParameter) {
    timer_init();
    cpu_init();
    ppu_init();

    ctx.running = true;
    ctx.paused = false;
    ctx.ticks = 0;

    while(ctx.running) {
        if (ctx.paused) {
            delay(10);
            continue;
        }

        if (!cpu_step()) {
            printf("CPU Stopped\n");
            return 0;
        }
    }

    return 0;
}
#else
//seperate thread for cpu
void *cpu_run(void *p) {
    timer_init();
    cpu_init();
    ppu_init();

    ctx.running = true;
    ctx.paused = false;
    ctx.ticks = 0;

    while(ctx.running) {
        if (ctx.paused) {
            delay(10);
            continue;
        }

        if (!cpu_step()) {
            printf("CPU Stopped\n");
            return 0;
        }
    }

    return 0;
}
#endif
int emu_run(char *path) {
    // if (argc < 2) {
    //     printf("Usage: emu <rom_file>\n");
    //     return -1;
    // }

    if (!cart_load(path)) {
        printf("Failed to load ROM file: %s\n", path);
        return -2;
    }

    printf("Cart loaded..\n");

    ui_init();
    
    #ifdef _WIN32
        if (!CreateThread(NULL,0, cpu_run, NULL, 0, NULL)) {
            fprintf(stderr, "[!]FAILED TO START MAIN CPU THREAD!\n");
            return -1;
        }
    #else
        pthread_t t1;
        if (pthread_create(&t1, NULL, cpu_run, NULL)) {
            fprintf(stderr, "[!]FAILED TO START MAIN CPU THREAD!\n");
            return -1;
        }
    #endif


    u32 prev_frame = 0;

    while(!ctx.die) {
        #ifdef _WIN32
            Sleep(1);
        #else
            usleep(1000);
        #endif
        ui_handle_events();
        if (prev_frame != ppu_get_context()->current_frame) {
            ui_update();
        }

        prev_frame = ppu_get_context()->current_frame;
    }
    if (cart_need_save()) {
        cart_battery_save();
    }
    return 0;
}

void emu_cycles(int cpu_cycles) {
    //TODO: needed for cycle accuracy later on
    //for each of the cpu cycles
    for (int i=0; i<cpu_cycles; i++) {
        for (int n=0; n<4; n++) {
            ctx.ticks++; //tick cpu
            timer_tick(); //tick timer
            ppu_tick();
        }

        dma_tick(); //outside, tick dma (every one cpu cycle)
    }
}