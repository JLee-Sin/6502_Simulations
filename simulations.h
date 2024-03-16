#ifndef CPU_SIM_SIMULATIONS_H
#define CPU_SIM_SIMULATIONS_H

typedef unsigned char Byte;
typedef unsigned short Word;
typedef unsigned int u32;

//Op Codes
#define LDA_im  ((Byte) 0xA9)  //Load Accumulator (Immediate Mode)
#define LDA_zp  ((Byte) 0xA5)  //Load Accumulator (Zero Page)
#define LDA_zpx ((Byte) 0xB5)  //Load Accumulator (Zero Page, x)
#define LDX_im  ((Byte) 0xA2)  //Load X Register (Immediate Mode)
#define LDY_im  ((Byte) 0xA0)  //Load Y Register (Immediate Mode)
#define JSR     ((Byte) 0x20)  //Jump to sub-Routine

u32 numCycles = 0;

void reset(struct CPU *pCpu, struct Memory *pMemory);

Byte fetchInstructionByte(Word *pCounter, struct Memory *pMemory, u32 *pCycles);

Byte readInstruction(Byte address, struct Memory *pMemory, u32 *pCycles);

Word fetchInstructionWord(Word *pCounter, struct Memory *pMemory, u32 *pCycles);

void writeWord(Word data, struct Memory *pMemory, u32 address, u32 *pCycles);

void exec(struct CPU *pCpu, struct Memory *pMemory, u32 *pCycles);

#endif //CPU_SIM_SIMULATIONS_H
