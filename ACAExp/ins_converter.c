//
//  ins_converter.c
//  ACAExp
//
//  Created by DengAden on 15/3/16.
//  Copyright (c) 2015年 Haowen Deng. All rights reserved.
//


#include "ins_converter.h"
#include <string.h>

char opcodes[100][20] = {
    /* All R-Type Insns are SPECIAL insns: Opcode = 0 */
    "SPECIAL",
    /* I-Type Insns. Max range: 1 - 63 */
    /* I-Type ALU Insns. Opcode range: 1 - 30 */
    "ADDI", "ADDUI","ANDI","MODI","MODUI","ORI","LHI","NOP", "SLLI","SRAI","SRLI","SUBI","SUBUI","XORI","MULI", "MULUI","DIVPI","DIVPUI","SEQI","SEQUI","SGEI", "SGEUI","SGTI","SGTUI","SLEI","SLEUI","SLTI","SLTUI","SNEI", "SNEUI",
    /* I-Type Branch and Jump Insns. Opcode range: 31 - 36 */
    "BEQZ","BNEZ","BFPF","BFPT","JR","JALR",
    /* I-Type Load and Store Insns. Opcode range: 37 - 48*/
    "LB","LBU","LH","LHU","LW","LF","LD","SB","SH","SW","SF", "SD",
    /* J-Type Insns. Opcode range: 49 - 52 */
    "J","JAL","TRAP","RFE",
    /* Break Instruction: Used to implement break at address */
    "BREAK",
    "END"
};

char functions[100][20] = {
    "ADD", "ADDU","AND","MOD","MODU","OR","SEQ","SGT","SGTU", "SLTU","SNE","SRL","SUB","MULU","DIVP","ADDD","ADDF","SEQU","SGE","SLE","SLEU","SNEU","SLL","SUBU", "XOR", "DIVPU","DIVD","DIVF","SGEU","SLT","SRA","MUL","MULTD","MULTF","SUBD","SUBF","DIV","DIVU","MULT","MULTU", "CVTD2F","CVTD2I","CVTF2D","CVTF2I","CVTI2D","CVTI2F", "EQD","GED","GEF","GTD","GTF","LEF","LTD","LTF","NED","MOVD","MOVF","MOVFP2I","MOVI2FP","MOVI2S","MOVS2I", "NEGD","NEGF",
    "END"
};

WORD get_index(char strings[100][20], char* str)
{
    WORD ind = 0;
    while(1)
    {
        if(strcmp(strings[ind],str)==0)
        {
            return ind;
        }
        else if(strcmp(strings[ind], "END")==0)
        {
            break;
        }
        ind++;
    }
    return 100;
}

void ins_encode(char* infile,char* outfile)
{
    FILE* fin;
    FILE* fout;
    WORD OPCODE = 100;
    WORD RS1 = 0;
    WORD RS2 = 0;
    WORD RD = 0;
    UHWORD FUNC = 100;
    UWORD UIMM = 0;
    WORD IMM = 0;
    UWORD OFFSET = 0;
    WORD ind = 0;
    UWORD res = 0;
    
    if((fin = fopen(infile, "r")) == NULL)
    {
        printf("Raw instruction file open failed...\n");
        return;
    }
    if((fout = fopen(outfile, "wb"))==NULL)
    {
        printf("Outfile open failed...\n");
        return;
    }
    char operand[20];
    while (1)
    {
        res = 0;
        if(fscanf(fin, "%s",operand) == EOF)
        {
//            printf("Fi...\n");
            break;
        }
        ind = get_index(opcodes, operand);
        if(ind == 100)
        {
            //  R-Type Instructions
            
            ind = get_index(functions, operand);
            if(ind == 100)
            {
                printf("Fault Instruction. Check Please...\n");
                return;
            }
            else
            {
                OPCODE = 0;
                FUNC = ind;
                fscanf(fin, " R%d,R%d,R%d\n",&RD,&RS1,&RS2);
                res = OPCODE | ((RS1 & 0x1f)<<21) | ((RS2 & 0x1f)<<16) | ((RD & 0x1f)<<11) |(FUNC & 0x7ff);
            }
        }
        else
        {
            OPCODE = ind;
            // I-Type Instructions
            if(ind >= 1 && ind <= 48)
            {
                if (ind >= 31 && ind <= 36) {
                    switch (ind)
                    {
                        case 31:
                        case 32:
                            fscanf(fin, " R%d,#%d\n",&RS1,&IMM);
                            RS2 = 0;
                            break;
                        case 33:
                        case 34:
                            fscanf(fin, " #%d\n",&IMM);
                            RS1 = 0;
                            RS2 = 0;
                            break;
                        case 35:
                        case 36:
                            fscanf(fin," R%d\n",&RS1);
                            RS2 = 0;
                            IMM = 0;
                            break;
                        default:
                            break;
                    }
                    res = ((OPCODE & 0x3f) << 26) | (RS1 & 0x1f)<< 21 | (RS2 & 0x1f) << 16 | (IMM & 0xffff);
                }
                else
                {
                    int len = (int)strlen(operand);
                    // Unsigned IMM
                    if(operand[len-2] == 'U')
                    {
                        
                        fscanf(fin, " R%d,R%d,#%d\n",&RS2,&RS1,&UIMM);
                        res = ((OPCODE & 0x3f) << 26) | (RS1 & 0x1f)<< 21 | (RS2 & 0x1f) << 16 | (UIMM & 0xffff);
                    }
                    //Signed IMM
                    else
                    {
                        
                        fscanf(fin, " R%d,R%d,#%d\n",&RS2,&RS1,&IMM);
                        res = ((OPCODE & 0x3f) << 26) | (RS1 & 0x1f)<< 21 | (RS2 & 0x1f) << 16 | (IMM & 0xffff);
                    }
                }
            }
            
            //J-Type Instructions
            else if (ind >= 49 && ind <= 52)
            {
                fscanf(fin, " #%d\n",&OFFSET);
                res = ((OPCODE & 0x3f) << 26) | (OFFSET & 0x3ffffff);
            }
        }
        fwrite(&res, sizeof(UWORD), 1, fout);
    }
    fclose(fin);
    fclose(fout);
}
