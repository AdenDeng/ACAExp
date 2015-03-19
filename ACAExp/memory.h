//
//  memory.h
//  ACAExp
//
//  Created by Haowen Deng on 15/3/15.
//  Copyright (c) 2015年 Haowen Deng. All rights reserved.
//

#include "types.h"

#ifndef ACAExp_memory_h
#define ACAExp_memory_h

#define MEM_SIZE 0x080000

static UBYTE* MEM;

void mem_init();

void mem_load_ins(WORD PC_ini,char* file_ini);

void mem_destroy();

void print_sys_info();

UBYTE read_mem_ubyte(WORD addr);

void write_mem_ubyte(WORD addr,UBYTE val);

BYTE read_mem_byte(WORD addr);

void write_mem_byte(WORD addr,BYTE val);

HWORD read_mem_hword(WORD addr);

void write_mem_hword(WORD addr,HWORD val);

UHWORD read_mem_uhword(WORD addr);

void write_mem_uhword(WORD addr,UHWORD val);

WORD read_mem_word(WORD addr);

void write_mem_word(WORD addr,WORD val);

UWORD read_mem_uword(WORD addr);

void write_mem_uword(WORD addr,UWORD val);

float read_mem_float(WORD addr);

void write_mem_float(WORD addr,float val);

double read_mem_double(WORD addr);

void write_mem_double(WORD addr,double val);

void rw_test();

#endif
