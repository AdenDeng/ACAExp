//
//  register.h
//  ACAExp
//
//  Created by Haowen Deng on 15/3/15.
//  Copyright (c) 2015年 Haowen Deng. All rights reserved.
//

#ifndef __ACAExp__register__
#define __ACAExp__register__

#include <stdio.h>
#include "types.h"

#define REG_SIZE 32

static UWORD* REGS;
static float* FREGS;

void reg_init();

void reg_destroy();

void write_reg_word(WORD addr,WORD val);

WORD read_reg_word(WORD addr);

void write_reg_uword(WORD addr,UWORD val);

UWORD read_reg_uword(WORD addr);

void write_freg_float(WORD addr,float val);

float read_freg_float(WORD addr);

void write_freg_double(WORD addr,double val);

double read_freg_double(WORD addr);

void reg_rw_test();
#endif /* defined(__ACAExp__register__) */
