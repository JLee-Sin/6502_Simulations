//
// Created by jayle on 3/15/2024.
//

#ifndef CPU_SIM_MAIN_H
#define CPU_SIM_MAIN_H

typedef unsigned char Byte;
typedef unsigned short Word;
typedef unsigned int u32;

//Op Codes
#define LDA_im  ((Byte) 0xA9)  //Load Accumulator (Immediate Mode)
#define LDA_zp  ((Byte) 0xA5)  //Load Accumulator (Zero Page)
#define LDA_zpx ((Byte) 0xB5)  //Load Accumulator (Zero Page, x)
#define LDX_im  ((Byte) 0xA2)  //Load X Register (Immediate Mode)
#define LDY_im  ((Byte) 0xA0)  //Load Y Register (Immediate Mode)

u32 numCycles = 0;

#endif //CPU_SIM_MAIN_H
