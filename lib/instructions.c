#include <instructions.h>
#include <cpu.h>

instruction instructions[0x100] = {
    [0x00] = {IN_NOP, AM_IMP},

    [0x05] = {IN_DEC, AM_R, RT_B},

    [0x0E] = {IN_LD, AM_R_D8, RT_C},

    [0xAF] = {IN_XOR, AM_R, RT_A},

    [0xC3] = {IN_JP, AM_D16},

    [0xF3] = {IN_DI}
};

instruction *instruction_by_opcode(u8 opcode) {
    if(instructions[opcode].type == IN_NONE){
        return NULL;
    }

    return &instructions[opcode]; //this returns the instructions related to the op code that is selected from the array
}