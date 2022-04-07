#pragma once

#include <common.h>

void stack_push(u8 data); //push 8 bit data to stack
void stack_push16(u16 data); //16 biy data to stack

u8 stack_pop(); //retreives 8-bit item on stack
u16 stack_pop16(); //retreives 16-bit item on stack
