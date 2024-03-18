//
// Created by jayle on 3/15/2024.
//

#ifndef CPU_SIM_CPU_H
#define CPU_SIM_CPU_H

typedef unsigned char Byte;
typedef unsigned short Word;

struct CPU {
    Word pCounter; //ProgramCounter
    Byte sPointer; //Stack Pointer

    //Registers, for clarity these are denoted with lower case letters
    Byte a; //Accumulator
    Byte x; //Index Register x
    Byte y; //Index Register y

    //Status flags for Processor Status, for clarity these are denoted with uppercase letters
    Byte C : 1; //Carry
    Byte Z : 1; //Zero
    Byte I : 1; //Interrupt Disable
    Byte D : 1; //Decimal Mode
    Byte B : 1; //Break Command
    Byte O : 1; //Overflow
    Byte N : 1; //Negative
};

void clearFlags(struct CPU *pCpu);

void clearRegisters(struct CPU *pCpu);

#endif //CPU_SIM_CPU_H
