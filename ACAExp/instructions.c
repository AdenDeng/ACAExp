//
//  instructions.c
//  ACAExp
//
//  Created by DengAden on 15/3/15.
//  Copyright (c) 2015年 Haowen Deng. All rights reserved.
//

#include "instructions.h"
#include "register.h"
#include "memory.h"

void ins_decode()
{
    OPCODE = (UBYTE)((ins >> 26) & 0x3f);
    RS1 = (UBYTE)((ins >> 21) & 0x1f);
    RS2 = (UBYTE)((ins >> 16) & 0x1f);
    RD = (UBYTE)((ins >> 11) & 0x1f);
    FUNC = (UHWORD)(ins & 0x7ff);
    UIMM = ins & 0xffff;
    IMM = (WORD)(ins & 0xffff);
    OFFSET = ins & 0x3ffffff;
}

void advance_PC()
{
    PC += 4;
}

void ADD()
{
    WORD rs1 = read_reg_word(RS1);
    WORD rs2 = read_reg_word(RS2);
    write_reg_word(RD, rs1+rs2);
    advance_PC();
}

void ADDU()
{
    UWORD rs1 = read_reg_uword(RS1);
    UWORD rs2 = read_reg_uword(RS2);
    write_reg_uword(RD, rs1+rs2);
    advance_PC();
}

void AND()
{
    REGS[RD] = REGS[RS1] & REGS[RS2];
    advance_PC();
}

void MOD()
{
    WORD rs1 = read_reg_word(RS1);
    WORD rs2 = read_reg_word(RS2);
    write_reg_word(RD, rs1%rs2);
    advance_PC();
}

void MODU()
{
    UWORD rs1 = read_reg_uword(RS1);
    UWORD rs2 = read_reg_uword(RS2);
    write_reg_uword(RD, rs1%rs2);
    advance_PC();
}

void OR()
{
    WORD rs1 = read_reg_word(RS1);
    WORD rs2 = read_reg_word(RS2);
    write_reg_word(RD, rs1 | rs2);
    advance_PC();
}

void SEQ()
{
    WORD rs1 = read_reg_word(RS1);
    WORD rs2 = read_reg_word(RS2);
    write_reg_word(RD, rs1==rs2);
    advance_PC();
}

void SEQU()
{
    UWORD rs1 = read_reg_uword(RS1);
    UWORD rs2 = read_reg_uword(RS2);
    write_reg_uword(RD, rs1==rs2);
    advance_PC();
}

void SGE()
{
    WORD rs1 = read_reg_word(RS1);
    WORD rs2 = read_reg_word(RS2);
    write_reg_word(RD, rs1>=rs2);
    advance_PC();
}

void SGEU()
{
    UWORD rs1 = read_reg_uword(RS1);
    UWORD rs2 = read_reg_uword(RS2);
    write_reg_uword(RD, rs1>=rs2);
    advance_PC();
}

void SGT()
{
    WORD rs1 = read_reg_word(RS1);
    WORD rs2 = read_reg_word(RS2);
    write_reg_word(RD, rs1>rs2);
    advance_PC();
}

void SGTU()
{
    UWORD rs1 = read_reg_uword(RS1);
    UWORD rs2 = read_reg_uword(RS2);
    write_reg_uword(RD, rs1>rs2);
    advance_PC();
}

void SLE()
{
    WORD rs1 = read_reg_word(RS1);
    WORD rs2 = read_reg_word(RS2);
    write_reg_word(RD, rs1<=rs2);
    advance_PC();
}

void SLEU()
{
    UWORD rs1 = read_reg_uword(RS1);
    UWORD rs2 = read_reg_uword(RS2);
    write_reg_uword(RD, rs1<=rs2);
    advance_PC();
}

void SLT()
{
    WORD rs1 = read_reg_word(RS1);
    WORD rs2 = read_reg_word(RS2);
    write_reg_word(RD, rs1<rs2);
    advance_PC();
}

void SLTU()
{
    UWORD rs1 = read_reg_uword(RS1);
    UWORD rs2 = read_reg_uword(RS2);
    write_reg_uword(RD, rs1<rs2);
    advance_PC();
}

void SNE()
{
    WORD rs1 = read_reg_word(RS1);
    WORD rs2 = read_reg_word(RS2);
    write_reg_word(RD, rs1!=rs2);
    advance_PC();
}

void SNEU()
{
    UWORD rs1 = read_reg_uword(RS1);
    UWORD rs2 = read_reg_uword(RS2);
    write_reg_uword(RD, rs1!=rs2);
    advance_PC();
}

void SLL()
{
    UWORD rs1 = read_reg_uword(RS1);
    UWORD rs2 = read_reg_uword(RS2);
    write_reg_uword(RD, rs1<<rs2);
    advance_PC();
}

void SRA()
{
    WORD rs1 = read_reg_word(RS1);
    WORD rs2 = read_reg_word(RS2);
    write_reg_word(RD, rs1>>rs2);
    advance_PC();
}

void SRL()
{
    UWORD rs1 = read_reg_uword(RS1);
    UWORD rs2 = read_reg_uword(RS2);
    write_reg_uword(RD, rs1>>rs2);
    advance_PC();
}

void SUB()
{
    WORD rs1 = read_reg_word(RS1);
    WORD rs2 = read_reg_word(RS2);
    write_reg_word(RD, rs1-rs2);
    advance_PC();
}

void SUBU()
{
    UWORD rs1 = read_reg_uword(RS1);
    UWORD rs2 = read_reg_uword(RS2);
    write_reg_uword(RD, rs1-rs2);
    advance_PC();
}

void XOR()
{
    WORD rs1 = read_reg_word(RS1);
    WORD rs2 = read_reg_word(RS2);
    write_reg_word(RD, rs1^rs2);
    advance_PC();
}

void MUL()
{
    WORD rs1 = read_reg_word(RS1);
    WORD rs2 = read_reg_word(RS2);
    write_reg_word(RD, rs1*rs2);
    advance_PC();
}

void MULU()
{
    UWORD rs1 = read_reg_uword(RS1);
    UWORD rs2 = read_reg_uword(RS2);
    write_reg_uword(RD, rs1*rs2);
    advance_PC();
}

void DIVP()
{
    WORD rs1 = read_reg_word(RS1);
    WORD rs2 = read_reg_word(RS2);
    write_reg_word(RD, rs1/rs2);
    advance_PC();
}

void DIVPU()
{
    UWORD rs1 = read_reg_uword(RS1);
    UWORD rs2 = read_reg_uword(RS2);
    write_reg_uword(RD, rs1/rs2);
    advance_PC();
}

void ADDD()
{
    double rs1 = read_freg_double(RS1);
    double rs2 = read_freg_double(RS2);
    write_freg_double(RD, rs1+rs2);
    advance_PC();
}

void ADDF()
{
    float  rs1 = read_freg_float(RS1);
    float rs2 = read_freg_float(RS2);
    write_freg_float(RD, rs1+rs2);
    advance_PC();
}

void DIVD()
{
    double rs1 = read_freg_double(RS1);
    double rs2 = read_freg_double(RS2);
    write_freg_double(RD, rs1/rs2);
    advance_PC();
}

void DIVF()
{
    float  rs1 = read_freg_float(RS1);
    float rs2 = read_freg_float(RS2);
    write_freg_float(RD, rs1/rs2);
    advance_PC();
}

void MULTD()
{
    double rs1 = read_freg_double(RS1);
    double rs2 = read_freg_double(RS2);
    write_freg_double(RD, rs1*rs2);
    advance_PC();
}

void MULTF()
{
    float  rs1 = read_freg_float(RS1);
    float rs2 = read_freg_float(RS2);
    write_freg_float(RD, rs1*rs2);
    advance_PC();
}

void SUBD()
{
    double rs1 = read_freg_double(RS1);
    double rs2 = read_freg_double(RS2);
    write_freg_double(RD, rs1-rs2);
    advance_PC();
}

void SUBF()
{
    float  rs1 = read_freg_float(RS1);
    float rs2 = read_freg_float(RS2);
    write_freg_float(RD, rs1-rs2);
    advance_PC();
}

void DIV()
{
    float rs1 = read_freg_float(RS1);
    float rs2 = read_freg_float(RS2);
    write_reg_word(RD, (WORD)rs1/rs2);
    advance_PC();
}

void DIVU()
{
    float rs1 = read_freg_float(RS1);
    float rs2 = read_freg_float(RS2);
    write_reg_uword(RD, (UWORD)rs1/rs2);
    advance_PC();
}

void MULT()
{
    float rs1 = read_freg_float(RS1);
    float rs2 = read_freg_float(RS2);
    write_reg_word(RD, (WORD)rs1*rs2);
    advance_PC();
}

void MULTU()
{
    float rs1 = read_freg_float(RS1);
    float rs2 = read_freg_float(RS2);
    write_reg_uword(RD, (UWORD)rs1*rs2);
    advance_PC();
}

void CVTD2F()
{
    double rs1 = read_freg_double(RS1);
    write_freg_float(RD, (float)rs1);
    advance_PC();
}

void CVTD2I()
{
    double rs1 = read_freg_double(RS1);
    write_reg_word(RD, (WORD)rs1);
    advance_PC();
}

void CVTF2D()
{
    float rs1 = read_freg_float(RS1);
    write_freg_double(RD, (double)rs1);
    advance_PC();
}

void CVTF2I()
{
    float rs1 = read_freg_float(RS1);
    write_reg_word(RD, (int)rs1);
    advance_PC();
}

void CVTI2F()
{
    WORD rs1 = read_reg_word(RS1);
    write_freg_float(RD, (float)rs1);
    advance_PC();
}

void GTD()
{
    double rs1 = read_freg_double(RS1);
    double rs2 = read_freg_double(RS2);
    FPS = (rs1 > rs2);
    advance_PC();
}

void GTF()
{
    float  rs1 = read_freg_float(RS1);
    float rs2 = read_freg_float(RS2);
    FPS = (rs1 > rs2);
    advance_PC();
}

void LED()
{
    double rs1 = read_freg_double(RS1);
    double rs2 = read_freg_double(RS2);
    FPS = (rs1 < rs2);
    advance_PC();
}

void LEF()
{
    float  rs1 = read_freg_float(RS1);
    float rs2 = read_freg_float(RS2);
    FPS = (rs1 < rs2);
    advance_PC();
}

void EQD()
{
    double rs1 = read_freg_double(RS1);
    double rs2 = read_freg_double(RS2);
    FPS = (rs1 == rs2);
    advance_PC();
}

void EQF()
{
    float  rs1 = read_freg_float(RS1);
    float rs2 = read_freg_float(RS2);
    FPS = (rs1 == rs2);
    advance_PC();
}

void GED()
{
    double rs1 = read_freg_double(RS1);
    double rs2 = read_freg_double(RS2);
    FPS = (rs1 >= rs2);
    advance_PC();
}

void GEF()
{
    float  rs1 = read_freg_float(RS1);
    float rs2 = read_freg_float(RS2);
    FPS = (rs1 >= rs2);
    advance_PC();
}

void LTD()
{
    double rs1 = read_freg_double(RS1);
    double rs2 = read_freg_double(RS2);
    FPS = (rs1 <= rs2);
    advance_PC();
}

void LTF()
{
    float  rs1 = read_freg_float(RS1);
    float rs2 = read_freg_float(RS2);
    FPS = (rs1 <= rs2);
    advance_PC();
}

void NED()
{
    double rs1 = read_freg_double(RS1);
    double rs2 = read_freg_double(RS2);
    FPS = (rs1 != rs2);
    advance_PC();
}

void NEF()
{
    float  rs1 = read_freg_float(RS1);
    float rs2 = read_freg_float(RS2);
    FPS = (rs1 != rs2);
    advance_PC();
}

void MOVD()
{
    double rs1 = read_freg_double(RS1);
    write_freg_double(RD, rs1);
    advance_PC();
}

void MOVF()
{
    float rs1 = read_freg_float(RS1);
    write_freg_float(RD, rs1);
    advance_PC();
}

void MOVFP2I()
{
    float rs1 = read_freg_float(RS1);
    write_reg_word(RD, (WORD)rs1);
    advance_PC();
}

void MOVI2FP()
{
    WORD rs1 = read_reg_word(RS1);
    write_freg_float(RD, (float)rs1);
    advance_PC();
}

void MOVI2S()
{
    FPS = read_reg_word(RS1);
    advance_PC();
}

void MOVS2I()
{
    write_reg_word(RD, FPS);
    advance_PC();
}

void NEGF()
{
    float rs1 = read_freg_float(RS1);
    UWORD* a = (UWORD*) &rs1;
    UWORD* b;
    *b = (*a)^0x80000000;
    float* c = (float *)b;
    write_freg_float(RD, *c);
    advance_PC();
}

void NEGD()
{
    double rs1 = read_freg_double(RS1);
    UWORD* a = (UWORD*) &rs1;
    UWORD* b;
    *b =(*a)^0x80000000;
    double* c = (double *)b;
    write_freg_double(RD, *c);
    advance_PC();
}

///////////////////////////////////////////////
///////////  R-Type Instructions  /////////////
///////////////////////////////////////////////

void ADDI()
{
    WORD rs1 = read_reg_word(RS1);
    write_reg_word(RS2, rs1+IMM);
    advance_PC();
}

void ADDUI()
{
    UWORD rs1 = read_reg_uword(RS1);
    write_reg_uword(RS2, rs1+UIMM);
    advance_PC();
}

void ANDI()
{
    UWORD rs1 = read_reg_uword(RS1);
    write_reg_uword(RS2, rs1 & UIMM);
    advance_PC();
}

void MODI()
{
    WORD rs1 = read_reg_word(RS1);
    write_reg_word(RS2, rs1 % IMM);
    advance_PC();
}

void MODUI()
{
    UWORD rs1 = read_reg_uword(RS1);
    write_reg_uword(RS2, rs1 % UIMM);
    advance_PC();
}

void ORI()
{
    UWORD rs1 = read_reg_uword(RS1);
    write_reg_uword(RS2, rs1 | UIMM);
    advance_PC();
}

void LHI()
{
    write_reg_uword(RS2, UIMM << 16);
    advance_PC();
}

void NOP()
{
    advance_PC();
}

void SLLI()
{
    UWORD rs1 = read_reg_uword(RS1);
    write_reg_uword(RS2, rs1 << UIMM);
    advance_PC();
}

void SRAI()
{
    WORD rs1 = read_reg_word(RS1);
    write_reg_word(RS2, rs1 >> UIMM);
    advance_PC();
}

void SRLI()
{
    WORD rs1 = read_reg_word(RS1);
    write_reg_word(RS2, rs1 << UIMM);
    advance_PC();
}

void SUBI()
{
    WORD rs1 = read_reg_word(RS1);
    write_reg_word(RS2, rs1 - UIMM);
    advance_PC();
}

void SUBUI()
{
    UWORD rs1 = read_reg_uword(RS1);
    write_reg_uword(RS2, rs1 - UIMM);
    advance_PC();
}

void XORI()
{
    UWORD rs1 = read_reg_uword(RS1);
    write_reg_uword(RS2, rs1 ^ UIMM);
    advance_PC();
}

void MULI()
{
    WORD rs1 = read_reg_word(RS1);
    write_reg_word(RS2, rs1 * IMM);
    advance_PC();
}

void MULUI()
{
    UWORD rs1 = read_reg_uword(RS1);
    write_reg_uword(RS2, rs1 * UIMM);
    advance_PC();
}

void DIVPI()
{
    WORD rs1 = read_reg_word(RS1);
    write_reg_word(RS2, rs1 / IMM);
    advance_PC();
}

void DIVPUI()
{
    UWORD rs1 = read_reg_uword(RS1);
    write_reg_uword(RS2, rs1 / UIMM);
    advance_PC();
}

void SEQI()
{
    WORD rs1 = read_reg_word(RS1);
    write_reg_word(RS2, rs1 == IMM);
    advance_PC();
}

void SEQUI()
{
    UWORD rs1 = read_reg_uword(RS1);
    write_reg_uword(RS2, rs1 == UIMM);
    advance_PC();
}

void SGEI()
{
    WORD rs1 = read_reg_word(RS1);
    write_reg_word(RS2, rs1 >= IMM);
    advance_PC();
}

void SGEUI()
{
    UWORD rs1 = read_reg_uword(RS1);
    write_reg_uword(RS2, rs1 >= UIMM);
    advance_PC();
}

void SGTI()
{
    WORD rs1 = read_reg_word(RS1);
    write_reg_word(RS2, rs1 > IMM);
    advance_PC();
}

void SGTUI()
{
    UWORD rs1 = read_reg_uword(RS1);
    write_reg_uword(RS2, rs1 > UIMM);
    advance_PC();
}

void SLEI()
{
    WORD rs1 = read_reg_word(RS1);
    write_reg_word(RS2, rs1 <= IMM);
    advance_PC();
}

void SLEUI()
{
    UWORD rs1 = read_reg_uword(RS1);
    write_reg_uword(RS2, rs1 <= UIMM);
    advance_PC();
}

void SLTI()
{
    WORD rs1 = read_reg_word(RS1);
    write_reg_word(RS2, rs1 < IMM);
    advance_PC();
}

void SLTUI()
{
    UWORD rs1 = read_reg_uword(RS1);
    write_reg_uword(RS2, rs1 < UIMM);
    advance_PC();
}

void SNEI()
{
    WORD rs1 = read_reg_word(RS1);
    write_reg_word(RS2, rs1 != IMM);
    advance_PC();
}

void SNEUI()
{
    UWORD rs1 = read_reg_uword(RS1);
    write_reg_uword(RS2, rs1 != UIMM);
    advance_PC();
}

void BEQZ()
{
    WORD rs1 = read_reg_word(RS1);
    if(rs1 == 0)
    {
        PC = PC + IMM - 4;
    }
    else    advance_PC();
}

void BNEZ()
{
    WORD rs1 = read_reg_word(RS1);
    if(rs1 != 0)
    {
        PC = PC + IMM - 4;
    }
    else    advance_PC();
}

void BFPF()
{
    if(FPS == 0)
    {
        PC = PC + IMM - 4;
    }
    else    advance_PC();
}

void BFPT()
{
    if(FPS != 0)
    {
        PC = PC + IMM - 4;
    }
    else    advance_PC();
}

void JR()
{
    PC = read_reg_word(RS1);
}

void JALR()
{
    
}

void LB()
{
    WORD rs1 = read_reg_word(RS1);
    WORD rs2 = (WORD)read_mem_byte(rs1+IMM);
    write_reg_word(RS2, rs2);
    advance_PC();
}

void LBU()
{
    WORD rs1 = read_reg_word(RS1);
    WORD rs2 = (WORD)read_mem_ubyte(rs1+IMM);
    write_reg_word(RS2, rs2);
    advance_PC();
}

void LH()
{
    WORD rs1 = read_reg_word(RS1);
    WORD rs2 = (WORD)read_mem_hword(rs1+IMM);
    write_reg_word(RS2, rs2);
    advance_PC();
}

void LHU()
{
    WORD rs1 = read_reg_word(RS1);
    WORD rs2 = (WORD)read_mem_uhword(rs1+IMM);
    write_reg_word(RS2, rs2);
    advance_PC();
}

void LW()
{
    WORD rs1 = read_reg_word(RS1);
    WORD rs2 = (WORD)read_mem_word(rs1+IMM);
    write_reg_word(RS2, rs2);
    advance_PC();
}

void LF()
{
    WORD rs1 = read_reg_word(RS1);
    float rs2 = read_mem_float(rs1+IMM);
    write_freg_float(RS2, rs2);
    advance_PC();
}

void LD()
{
    WORD rs1 = read_reg_word(RS1);
    double rs2 = read_mem_double(rs1+IMM);
    write_freg_double(RS2, rs2);
    advance_PC();
}

void SB()
{
    WORD rs1 = read_reg_word(RS1);
    WORD rs2 = read_reg_word(RS2);
    write_mem_byte(rs1+IMM, (BYTE)rs2);
    advance_PC();
}

void SH()
{
    WORD rs1 = read_reg_word(RS1);
    WORD rs2 = read_reg_word(RS2);
    write_mem_hword(rs1+IMM, (HWORD)rs2);
    advance_PC();
}

void SW()
{
    WORD rs1 = read_reg_word(RS1);
    WORD rs2 = read_reg_word(RS2);
    write_mem_word(rs1+IMM, (WORD)rs2);
    advance_PC();
}

void SF()
{
    WORD rs1 = read_reg_word(RS1);
    float rs2 = read_freg_float(RS2);
    write_mem_float(rs1+IMM, rs2);
    advance_PC();
}

void SD()
{
    WORD rs1 = read_reg_word(RS1);
    double rs2 = read_freg_double(RS2);
    write_mem_double(rs1+IMM, rs2);
    advance_PC();
}

void J()
{
    PC = PC + OFFSET - 4;
}

void JAL()
{
    PC = PC + OFFSET - 4;
}

void TRAP()
{
    
}

void RFE()
{
    
}

void exec_ins(WORD PC_ini)
{
    PC = PC_ini;
    while (PC) {
        ins = read_mem_uword(PC);
        ins_decode();
        if (OPCODE) {
            switch (OPCODE)
            {
                case OP_ADDI:
                    ADDI();
                    break;
                case OP_ADDUI:
                    ADDUI();
                    break;
                case OP_ANDI:
                    ANDI();
                    break;
                case OP_MODI:
                    MODI();
                    break;
                case OP_MODUI:
                    MODUI();
                    break;
                case OP_ORI:
                    ORI();
                    break;
                case OP_LHI:
                    LHI();
                    break;
                case OP_NOP:
                    NOP();
                    break;
                case OP_SLLI:
                    SLLI();
                    break;
                case OP_SRAI:
                    SRAI();
                    break;
                case OP_SRLI:
                    SRLI();
                    break;
                case OP_SUBI:
                    SUBI();
                    break;
                case OP_SUBUI:
                    SUBUI();
                    break;
                case OP_XORI:
                    XORI();
                    break;
                case OP_MULI:
                    MULI();
                    break;
                case OP_MULUI:
                    MULUI();
                    break;
                case OP_DIVPI:
                    DIVPI();
                    break;
                case OP_DIVPUI:
                    DIVPUI();
                    break;
                case OP_SEQI:
                    SEQI();
                    break;
                case OP_SEQUI:
                    SEQUI();
                    break;
                case OP_SGEI:
                    SGEI();
                    break;
                case OP_SGEUI:
                    SGEUI();
                    break;
                case OP_SGTI:
                    SGTI();
                    break;
                case OP_SGTUI:
                    SGTUI();
                    break;
                case OP_SLEI:
                    SLEI();
                    break;
                case OP_SLEUI:
                    SLEUI();
                    break;
                case OP_SLTI:
                    SLTI();
                    break;
                case OP_SLTUI:
                    SLTUI();
                    break;
                case OP_SNEI:
                    SNEI();
                    break;
                case OP_SNEUI:
                    SNEUI();
                    break;
                case OP_BEQZ:
                    BEQZ();
                    break;
                case OP_BNEZ:
                    BNEZ();
                    break;
                case OP_BFPF:
                    BFPF();
                    break;
                case OP_BFPT:
                    BFPT();
                    break;
                case OP_JR:
                    JR();
                    break;
                case OP_JALR:
                    JALR();
                    break;
                case OP_LB:
                    LB();
                    break;
                case OP_LBU:
                    LBU();
                    break;
                case OP_LH:
                    LH();
                    break;
                case OP_LHU:
                    LHU();
                    break;
                case OP_LW:
                    LW();
                    break;
                case OP_LF:
                    LF();
                    break;
                case OP_LD:
                    LD();
                    break;
                case OP_SB:
                    SB();
                    break;
                case OP_SH:
                    SH();
                    break;
                case OP_SW:
                    SW();
                    break;
                case OP_SF:
                    SF();
                    break;
                case OP_SD:
                    SD();
                    break;
                case OP_J:
                    J();
                    break;
                case OP_JAL:
                    JAL();
                    break;
                case OP_TRAP:
                    TRAP();
                    break;
                case OP_RFE:
                    RFE();
                    break;
                default:
                    break;
            }
        }
        else
        {
            switch (FUNC) {
                case OP_ADD:
                    ADD();
                    break;
                case OP_ADDU:
                    ADDU();
                    break;
                case OP_AND:
                    AND();
                    break;
                case OP_MOD:
                    MOD();
                    break;
                case OP_MODU:
                    MODU();
                    break;
                case OP_OR:
                    OR();
                    break;
                case OP_SEQ:
                    SEQ();
                    break;
                case OP_SGT:
                    SGT();
                    break;
                case OP_SGTU:
                    SGTU();
                    break;
                case OP_SLTU:
                    SLTU();
                    break;
                case OP_SNE:
                    SNE();
                    break;
                case OP_SRL:
                    SRL();
                    break;
                case OP_SUB:
                    SUB();
                    break;
                case OP_MULU:
                    MULU();
                    break;
                case OP_DIVP:
                    DIVPI();
                    break;
                case OP_ADDD:
                    ADDD();
                    break;
                case OP_ADDF:
                    ADDF();
                    break;
                case OP_SEQU:
                    SEQU();
                    break;
                case OP_SGE:
                    SGE();
                    break;
                case OP_SLE:
                    SLE();
                    break;
                case OP_SLEU:
                    SLEU();
                    break;
                case OP_SNEU:
                    SNEU();
                    break;
                case OP_SLL:
                    SLL();
                    break;
                case OP_SUBU:
                    SUBU();
                    break;
                case OP_XOR:
                    XOR();
                    break;
                case OP_DIVPU:
                    DIVPU();
                    break;
                case OP_DIVD:
                    DIVD();
                    break;
                case OP_DIVF:
                    DIVF();
                    break;
                case OP_SGEU:
                    SGEU();
                    break;
                case OP_SLT:
                    SLT();
                    break;
                case OP_SRA:
                    SRA();
                    break;
                case OP_MUL:
                    MUL();
                    break;
                case OP_MULTD:
                    MULTD();
                    break;
                case OP_MULTF:
                    MULTF();
                    break;
                case OP_SUBD:
                    SUBD();
                    break;
                case OP_SUBF:
                    SUBF();
                    break;
                case OP_DIV:
                    DIV();
                    break;
                case OP_DIVU:
                    DIVU();
                    break;
                case OP_MULT:
                    MULT();
                    break;
                case OP_MULTU:
                    MULTU();
                    break;
                case OP_CVTD2F:
                    CVTD2F();
                    break;
                case OP_CVTD2I:
                    CVTD2I();
                    break;
                case OP_CVTF2D:
                    CVTF2D();
                    break;
                case OP_CVTF2I:
                    CVTF2I();
                    break;
                case OP_CVTI2D:
                    CVTF2D();
                    break;
                case OP_CVTI2F:
                    CVTI2F();
                    break;
                case OP_EQD:
                    EQD();
                    break;
                case OP_GED:
                    GED();
                    break;
                case OP_GEF:
                    GEF();
                    break;
                case OP_GTD:
                    GTD();
                    break;
                case OP_GTF:
                    GTF();
                    break;
                case OP_LEF:
                    LEF();
                    break;
                case OP_LTD:
                    LTD();
                    break;
                case OP_LTF:
                    LTF();
                    break;
                case OP_NED:
                    NED();
                    break;
                case OP_MOVD:
                    MOVD();
                    break;
                case OP_MOVF:
                    MOVF();
                    break;
                case OP_MOVFP2I:
                    MOVFP2I();
                    break;
                case OP_MOVI2FP:
                    MOVI2FP();
                    break;
                case OP_MOVI2S:
                    MOVI2S();
                    break;
                case OP_MOVS2I:
                    MOVS2I();
                    break;
                case OP_NEGD:
                    NEGD();
                    break;
                case OP_NEGF:
                    NEGF();
                    break;
                default:
                    break;
            }
        }
    }
}


