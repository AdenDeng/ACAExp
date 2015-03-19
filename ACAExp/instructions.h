//
//  instructions.h
//  ACAExp
//
//  Created by DengAden on 15/3/15.
//  Copyright (c) 2015年 Haowen Deng. All rights reserved.
//
//This is a test
#ifndef __ACAExp__instructions__
#define __ACAExp__instructions__

#include <stdio.h>
#include "types.h"

static UWORD ins;
static WORD PC;
static UBYTE OPCODE;
static UBYTE RS1;
static UBYTE RS2;
static UBYTE RD;
static UHWORD FUNC;
static UWORD UIMM;
static WORD IMM;
static UWORD OFFSET;

static WORD FPS = 0;

enum opcodes {
    /* All R-Type Insns are SPECIAL insns: Opcode = 0 */
    OP_SPECIAL = 0,
    /* I-Type Insns. Max range: 1 - 63 */
    /* I-Type ALU Insns. Opcode range: 1 - 30 */
    OP_ADDI, OP_ADDUI, OP_ANDI, OP_MODI, OP_MODUI,OP_ORI, OP_LHI, OP_NOP, OP_SLLI, OP_SRAI, OP_SRLI, OP_SUBI, OP_SUBUI, OP_XORI, OP_MULI, OP_MULUI, OP_DIVPI, OP_DIVPUI, OP_SEQI, OP_SEQUI, OP_SGEI, OP_SGEUI, OP_SGTI, OP_SGTUI, OP_SLEI, OP_SLEUI, OP_SLTI, OP_SLTUI, OP_SNEI, OP_SNEUI,
    /* I-Type Branch and Jump Insns. Opcode range: 31 - 36 */
    OP_BEQZ, OP_BNEZ, OP_BFPF, OP_BFPT, OP_JR, OP_JALR,
    /* I-Type Load and Store Insns. Opcode range: 37 - 48*/
    OP_LB, OP_LBU,OP_LH, OP_LHU, OP_LW, OP_LF, OP_LD, OP_SB, OP_SH, OP_SW, OP_SF, OP_SD,
    /* J-Type Insns. Opcode range: 49 - 52 */
    OP_J, OP_JAL, OP_TRAP, OP_RFE,
    /* Break Instruction: Used to implement break at address */
    OP_BREAK,
    /* !!! Do *NOT* remove this entry !!!*/
    NUM_OPCODES
};

enum functions {
    OP_ADD = 0, OP_ADDU, OP_AND, OP_MOD,OP_MODU,OP_OR, OP_SEQ,OP_SGT, OP_SGTU, OP_SLTU, OP_SNE, OP_SRL, OP_SUB,OP_MULU, OP_DIVP, OP_ADDD, OP_ADDF,OP_SEQU, OP_SGE, OP_SLE, OP_SLEU, OP_SNEU, OP_SLL, OP_SUBU, OP_XOR, OP_DIVPU,OP_DIVD, OP_DIVF,OP_SGEU, OP_SLT, OP_SRA,OP_MUL,OP_MULTD,OP_MULTF, OP_SUBD, OP_SUBF, OP_DIV, OP_DIVU, OP_MULT, OP_MULTU, OP_CVTD2F, OP_CVTD2I, OP_CVTF2D,OP_CVTF2I, OP_CVTI2D, OP_CVTI2F, OP_EQD,OP_GED, OP_GEF, OP_GTD, OP_GTF,OP_LEF, OP_LTD, OP_LTF, OP_NED,OP_MOVD, OP_MOVF, OP_MOVFP2I, OP_MOVI2FP, OP_MOVI2S, OP_MOVS2I, OP_NEGD, OP_NEGF,
    /* !!! Do *NOT* remove this entry !!!*/
    NUM_FUNCS
};

void ins_decode();

void advance_PC();

void ADD();

void ADDU();

void AND();

void MOD();

void MODU();

void OR();

void SEQ();

void SEQU();

void SGE();

void SGEU();

void SGT();

void SGTU();

void SLE();

void SLEU();

void SLT();

void SLTU();

void SNE();

void SNEU();

void SLL();

void SRA();

void SRL();

void SUB();

void SUBU();

void XOR();

void MUL();

void MULU();

void DIVP();

void DIVPU();

void ADDD();

void ADDF();

void DIVD();

void DIVF();

void MULTD();

void MULTF();

void SUBD();

void SUBF();

void DIV();

void DIVU();

void MULT();

void MULTU();

void CVTD2F();

void CVTD2I();

void CVTF2D();

void CVTF2I();

void CVTI2F();

void GTD();

void GTF();

void LED();

void LEF();

void EQD();

void EQF();

void GED();

void GEF();

void LTD();

void LTF();

void NED();

void NEF();

void MOVD();

void MOVF();

void MOVFP2I();

void MOVI2FP();

void MOVI2S();

void MOVS2I();

void NEGF();

void NEGD();

///////////////////////////////////////////////
///////////  R-Type Instructions  /////////////
///////////////////////////////////////////////

void ADDI();

void ADDUI();

void ANDI();

void MODI();

void MODUI();

void ORI();

void LHI();

void NOP();

void SLLI();

void SRAI();

void SRLI();

void SUBI();

void SUBUI();

void XORI();

void MULI();

void MULUI();

void DIVPI();

void DIVPUI();

void SEQI();

void SEQUI();

void SGEI();

void SGEUI();

void SGTI();

void SGTUI();

void SLEI();

void SLEUI();

void SLTI();

void SLTUI();

void SNEI();

void SNEUI();

void BEQZ();

void BNEZ();

void BFPF();

void BFPT();

void JR();

void JALR();

void LB();

void LBU();

void LH();

void LHU();

void LW();

void LF();

void LD();

void SB();

void SH();

void SW();

void SF();

void SD();

void J();

void JAL();

void TRAP();

void RFE();

void exec_ins(WORD PC_ini);
#endif /* defined(__ACAExp__instructions__) */
