#pragma once

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

//gets the bits
#define BIT(a, n) ((a & (1 << n)) ? 1 : 0)
                                //sets bit when on     //clears bit when off
#define BIT_SET(a, n, on) { if (on) a |= (1 << n); else a &= ~(1 << n);}

#define BETWEEN(a, b, c) ((a >= b) && (a <= c))

void delay(u32 ms);

#define NO_IMPL {fprintf(stderr, "NOT YET IMPLEMENTED\n"); exit(-100);}
//A tool to exit code when things are not implemented during development process, exits with code 100