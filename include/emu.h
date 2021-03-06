#pragma once

#include <common.h>

typedef struct {
    bool paused;
    bool running;
    bool die;
    u64 ticks;
} emu_context;

int emu_run(char *path);

emu_context *emu_get_context();

void emu_cycles(int cpu_cycles); //going to be used to synchronise the PPU, Timer, CPU etc.
