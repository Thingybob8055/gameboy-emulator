#pragma once

#include <common.h>
#include <instructions.h>

typedef struct {
    /* one for each 8-bit register
    one for program counter and stack pointer, 16 bits */
    u8 a;
    u8 f;
    u8 b;
    u8 c;
    u8 d;
    u8 e;
    u8 h;
    u8 l;
    u16 pc;
    u16 sp;
} cpu_registers;

typedef struct {
    /* The context of the cpu is basically the state of the registers */
    cpu_registers regs;

    //data fetched from a register
    //current fetch.....
    u16 fetched_data;
    u16 mem_dest; //memory destination
    bool dest_is_mem;
    u8 cur_opcode;
    instruction *cur_inst; //memory destination

    bool halted; //is cpu halted?
    bool stepping; //is cpu in stepping mode?

    bool int_master_enabled;
    bool enabling_ime;
    u8 ie_register;
    u8 int_flags;
    
} cpu_context;

//returns values for the registers
cpu_registers *cpu_get_regs();

void cpu_init();
bool cpu_step();

//this is a function pointer called IN_PROC (instruction processor)
//A function that returns void, and takes in cpu_context pointer
typedef void (*IN_PROC)(cpu_context *);
//the function below gets the function processor (IN_PROC) by the instruction type
IN_PROC inst_get_processor(in_type type);
//we create a function for each instruction

//Pandocs has more detail
//The Z (zero flag) is stored in the flag register and the BIT Macro
//is used to get the bits, and for Flag Z, we get bit 7

//gives value for zero andcarry flag
#define CPU_FLAG_Z BIT(ctx->regs.f, 7)
#define CPU_FLAG_N BIT(ctx->regs.f, 6)
#define CPU_FLAG_H BIT(ctx->regs.f, 5)
#define CPU_FLAG_C BIT(ctx->regs.f, 4)

u16 cpu_read_reg(reg_type rt);
void cpu_set_reg(reg_type rt, u16 val);

u8 cpu_get_ie_register();
void cpu_set_ie_register(u8 n);

u8 cpu_read_reg8(reg_type rt);
void cpu_set_reg8(reg_type rt, u8 val);

u8 cpu_get_int_flags();
void cpu_set_int_flags(u8 value);

void inst_to_str(cpu_context *ctx, char *str);
