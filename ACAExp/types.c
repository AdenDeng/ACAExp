//
//  types.c
//  ACAExp
//
//  Created by DengAden on 15/3/15.
//  Copyright (c) 2015年 Haowen Deng. All rights reserved.
//

#include <stdio.h>
#include "types.h"

void print_sys_info()
{
    printf("------------System Info-------------\n");
    printf("BYTE:%lu byte\n",sizeof(BYTE));
    printf("HWORD:%lu bytes\n",sizeof(HWORD));
    printf("WORD:%lu bytes\n",sizeof(WORD));
    printf("DWORD:%lu bytes\n",sizeof(DWORD));
    printf("float:%lu bytes\n",sizeof(float));
    printf("double:%lu bytes\n",sizeof(double));
    printf("------------------------------------\n\n");
}
