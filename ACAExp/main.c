//
//  main.c
//  test
//
//  Created by Haowen Deng on 15/3/11.
//  Copyright (c) 2015年 Deng Haowen. All rights reserved.
//

#include <stdio.h> 
#include <stdlib.h>
#include "memory.h"
#include "register.h"
#include "instructions.h"
#include "ins_converter.h"

int main(int argc,char** argv)
{
    //Print the size of each type
    print_sys_info();
    
    //Test memory read and write operations
    rw_test();
    
    //Test register read and write operations
    reg_rw_test();
    
    //Simulation Execution
    mem_init();
    reg_init();
    
    //The start addr of program memory
    WORD program_addr = 0x10000;

    WORD i1 = 16, i2 = -35, i3;
    write_reg_word(2, i1);
    write_reg_word(3, i2);

    ins_encode("/Users/deng/Projects/ACAExp/ACAExp/instructions", "/Users/deng/Projects/ACAExp/ACAExp/out.dat");
    
    // Loading the instructions into the program memory
    mem_load_ins(program_addr, "/Users/deng/Projects/ACAExp/ACAExp/out.dat");
    exec_ins(program_addr);
    
    i3 = read_reg_word(1);
    printf("i3 = %d \n",i3);
    
    
    mem_destroy();
    reg_destroy();
    
    return 0;
}
