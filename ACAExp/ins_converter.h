//
//  ins_converter.h
//  ACAExp
//
//  Created by DengAden on 15/3/16.
//  Copyright (c) 2015年 Haowen Deng. All rights reserved.
//

#ifndef __ACAExp__ins_converter__
#define __ACAExp__ins_converter__

#include <stdio.h>
#include <string.h>
#include "types.h"

void ins_encode(char* infile, char* outfile);
WORD get_index(char strings[100][20],char* str);


#endif /* defined(__ACAExp__ins_converter__) */
