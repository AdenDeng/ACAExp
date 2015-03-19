//
//  register.c
//  ACAExp
//
//  Created by Haowen Deng on 15/3/15.
//  Copyright (c) 2015年 Haowen Deng. All rights reserved.
//

#include "register.h"
#include <stdlib.h>

void reg_init()
{
    REGS = (UWORD *)calloc(REG_SIZE,sizeof(UWORD));
    if(REGS == NULL)
    {
        printf("Error:General Registers initialization failed...\n");
        return;
    }
    FREGS = (float *)calloc(REG_SIZE,sizeof(float));
    if(FREGS == NULL)
    {
        printf("Error:Float Registers initialization failed...\n");
        return;
    }
}

void reg_destroy()
{
    free(REGS);
    free(FREGS);
}

void write_reg_word(WORD addr,WORD val)
{
    *((WORD*)REGS+addr) = val;
}

WORD read_reg_word(WORD addr)
{
    return *((WORD*)REGS+addr);
}

void write_reg_uword(WORD addr,UWORD val)
{
    *(REGS+addr) = val;
}

UWORD read_reg_uword(WORD addr)
{
    return *(REGS+addr);
}

void write_freg_float(WORD addr,float val)
{
    *(FREGS+addr) = val;
}

float read_freg_float(WORD addr)
{
    return *(FREGS+addr);
}

void write_freg_double(WORD addr,double val)
{
    *((double*)(FREGS+addr)) = val;
}

double read_freg_double(WORD addr)
{
    return *((double*)(FREGS+addr));
}

void reg_rw_test()
{
    reg_init();
    printf("-------------Register R/W Test-------------\n");
    double d1,d2;
    d1 = 0xf5f5f5f5;
    WORD addr = 5;
    write_freg_double(addr, d1);
    d2 = read_freg_double(addr);
    printf("The value 0xf5f5f5f5 of d2 is %f\n",d2);
    
    d1 = 4126537216.315;
    write_freg_double(addr, d1);
    d2 = read_freg_double(addr);
    printf("The value 4126537216.315 of d2 is %f\n",d2);
    
    float f1,f2;
    f1 = 0xf5f5f5f5;
    write_freg_float(addr, f1);
    f2 = read_freg_float(addr);
    printf("The value 0xf5f5f5f5 of f2 is %f\n",f2);
    
    f1 = 4126537216.315;
    write_freg_float(addr, f1);
    f2 = read_freg_float(addr);
    printf("The value 4126537216.315 of f2 is %f\n",f2);
    printf("-------------------------------------------\n\n\n");
    
    reg_destroy();
}