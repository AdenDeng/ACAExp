//
//  memory.c
//  ACAExp
//
//  Created by Haowen Deng on 15/3/15.
//  Copyright (c) 2015年 Haowen Deng. All rights reserved.
//

#include "memory.h"
#include <stdio.h>
#include <stdlib.h>

void mem_init()
{
    MEM = (UBYTE*)calloc(MEM_SIZE, sizeof(UBYTE));
    if (MEM == NULL) {
        printf("Error:Memory allocation failed...\n");
        return;
    }
}

void mem_load_ins(WORD PC_ini,char* file_ini)
{
    FILE* fp = fopen(file_ini, "r");
    if (fp == NULL)
    {
        printf("Load instructions failed...\n");
        return;
    }
    fread(MEM+PC_ini, sizeof(UWORD), 100, fp);
//    printf("%x\n",*((UWORD*)(MEM+PC_ini)));
//    printf("%x\n",*((UWORD*)(MEM+PC_ini+4)));
    fclose(fp);
}

void mem_destroy()
{
    free(MEM);
}

UBYTE read_mem_ubyte(WORD addr)
{
    return *((UBYTE *)(MEM+addr));
}

void write_mem_ubyte(WORD addr,UBYTE val)
{
    *((unsigned char*)(MEM+addr)) = val;
}

BYTE read_mem_byte(WORD addr)
{
    return *((BYTE *)(MEM+addr));
}

void write_mem_byte(WORD addr,BYTE val)
{
    *((BYTE*)(MEM+addr)) = val;
}

HWORD read_mem_hword(WORD addr)
{
    return *((HWORD *)(MEM+addr));
}

void write_mem_hword(WORD addr,HWORD val)
{
    *((HWORD*)(MEM+addr)) = val;
}

UHWORD read_mem_uhword(WORD addr)
{
    return *((UHWORD *)(MEM+addr));
}

void write_mem_uhword(WORD addr,UHWORD val)
{
    *((UHWORD*)(MEM+addr)) = val;
}

WORD read_mem_word(WORD addr)
{
    return *((WORD *)(MEM+addr));
}

void write_mem_word(WORD addr,WORD val)
{
    *((WORD*)(MEM+addr)) = val;
}

UWORD read_mem_uword(WORD addr)
{
    return *((UWORD *)(MEM+addr));
}

void write_mem_uword(WORD addr,UWORD val)
{
    *((UWORD*)(MEM+addr)) = val;
}

float read_mem_float(WORD addr)
{
    return *((float *)(MEM+addr));
}

void write_mem_float(WORD addr,float val)
{
    *((float*)(MEM+addr)) = val;
}

double read_mem_double(WORD addr)
{
    return *((double *)(MEM+addr));
}

void write_mem_double(WORD addr,double val)
{
    *((double*)(MEM+addr)) = val;
}

void rw_test()
{
    
    printf("----------Memory Read/Write Test-----------\n");
    mem_init();
    
    WORD addr = 256;
    ///////////////////////////////////////
    UBYTE ub1,ub2;
    ub1 = 0x0f5;
    write_mem_ubyte(addr, ub1);
    ub2 = read_mem_ubyte(addr);
    printf("The value 0xf5 in ub2 is %u \n",ub2);
    
    ///////////////////////////////////////
    BYTE b1,b2;
    b1 = 0x0f5;
    write_mem_byte(addr, b1);
    b2 = read_mem_ubyte(addr);
    printf("The value 0xf5 in b2 is %d \n",b2);
    
    ///////////////////////////////////////
    HWORD h1,h2;
    h1 = 0xf5f5;
    write_mem_hword(addr, h1);
    h2 = read_mem_hword(addr);
    printf("The value 0xf5f5 in h2 is %d \n",h2);
    
    ///////////////////////////////////////
    UHWORD uh1,uh2;
    uh1 = 0xf5f5;
    write_mem_uhword(addr, uh1);
    uh2 = read_mem_uhword(addr);
    printf("The value 0xf5f5 in uh2 is %u \n",uh2);
    
    ///////////////////////////////////////
    WORD w1,w2;
    w1 = 0xf5f5f5f5;
    write_mem_word(addr, w1);
    w2 = read_mem_word(addr);
    printf("The value 0xf5f5f5f5 in w2 is %d \n",w2);
    
    ///////////////////////////////////////
    UWORD uw1,uw2;
    uw1 = 0xf5f5f5f5;
    write_mem_uword(addr, uw1);
    uw2 = read_mem_uword(addr);
    printf("The value 0xf5f5f5f5 in uw2 is %u \n",uw2);
    
    ///////////////////////////////////////
    float f1,f2;
    f1 = 0xf5f5f5f5;
    write_mem_float(addr, h1);
    f2 = read_mem_float(addr);
    printf("The value 0xf5f5f5f5 in f2 is %f \n",f2);
    
    ///////////////////////////////////////
    double d1,d2;
    d1 = 0xf5f5f5f5;
    write_mem_double(addr, d1);
    d2 = read_mem_double(addr);
    printf("The value 0xf5f5f5f5 in d2 is %f \n",d2);
    
    
    mem_destroy();
    printf("-------------------------------------------\n\n");
}
