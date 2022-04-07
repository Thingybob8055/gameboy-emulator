#pragma once

#include <common.h>

//these are memory mapped registes
//PANDOCS has information regarding how to deal with these registers
typedef struct {
    u16 div;
    u8 tima;
    u8 tma;
    u8 tac;
} timer_context;

void timer_init();
void timer_tick();

void timer_write(u16 address, u8 value);
u8 timer_read(u16 address);

timer_context *timer_get_context();
