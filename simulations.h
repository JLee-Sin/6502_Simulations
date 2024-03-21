#ifndef CPU_SIM_SIMULATIONS_H
#define CPU_SIM_SIMULATIONS_H

typedef unsigned char Byte;
typedef unsigned short Word;
typedef unsigned int u32;

//Op Codes (Load/Store)
#define LDA_im  ((Byte) 0xA9)  //Load Accumulator (Immediate Mode)
#define LDA_zp  ((Byte) 0xA5)  //Load Accumulator (Zero Page)
#define LDA_zpx ((Byte) 0xB5)  //Load Accumulator (Zero Page, x)
#define LDA_ab  ((Byte) 0xAD)  //Load Accumulator (Absolute Mode)
#define LDA_abx ((Byte) 0xBD)  //Load Accumulator (Absolute Mode, x)
#define LDA_aby ((Byte) 0xB9)  //Load Accumulator (Absolute Mode, y)
#define LDA_inx ((Byte) 0xA1)  //Load Accumulator (Indirect Mode, x)
#define LDA_iny ((Byte) 0xB1)  //Load Accumulator (Indirect Mode, y)

#define LDX_im  ((Byte) 0xA2)  //Load x Register (Immediate Mode)
#define LDX_zp  ((Byte) 0xA6)  //Load x Register (Zero Page)
#define LDX_zpy ((Byte) 0xB6)  //Load x Register (Zero Page, y)
#define LDX_ab  ((Byte) 0xAE)  //Load x Register (Absolute Mode)
#define LDX_aby ((Byte) 0xBE)  //Load x Register (Absolute Mode, y)

#define LDY_im  ((Byte) 0xA0)  //Load y Register (Immediate Mode)
#define LDY_zp  ((Byte) 0xA4)  //Load y Register (Zero Page)
#define LDY_zpx ((Byte) 0xB4)  //Load y Register (Zero Page, x)
#define LDY_ab  ((Byte) 0xAC)  //Load y Register (Absolute Mode)
#define LDY_abx ((Byte) 0xBC)  //Load y Register (Absolute Mode, x)

#define STA_zp  ((Byte) 0x85)  //Store Accumulator (Zero Page)
#define STA_zpx ((Byte) 0x95)  //Store Accumulator (Zero Page, x)
#define STA_ab  ((Byte) 0x8D)  //Store Accumulator (Absolute Mode)
#define STA_abx ((Byte) 0x9D)  //Store Accumulator (Absolute Mode, x)
#define STA_aby ((Byte) 0x99)  //Store Accumulator (Absolute Mode, y)
#define STA_inx ((Byte) 0x81)  //Store Accumulator (Indirect Mode, x)
#define STA_iny ((Byte) 0x91)  //Store Accumulator (Indirect Mode, y)

#define STX_zp  ((Byte) 0x86)  //Store x Register (Zero Page)
#define STX_zpy ((Byte) 0x96)  //Store x Register (Zero Page, y)
#define STX_ab  ((Byte) 0x8E)  //Store x Register (Absolute Mode)

#define STY_zp  ((Byte) 0x84)  //Store y Register (Zero Page)
#define STY_zpx ((Byte) 0x94)  //Store y Register (Zero Page, x)
#define STY_ab  ((Byte) 0x8C)  //Store y Register (AbsoluteMode)

//Op Codes (Register Transfers)
#define TAX     ((Byte) 0xAA)  //Transfer Accumulator to x (Implied)
#define TAY     ((Byte) 0xA8)  //Transfer Accumulator to y (Implied)
#define TXA     ((Byte) 0x8A)  //Transfer x to Accumulator (Implied)
#define TYA     ((Byte) 0x98)  //Transfer y to Accumulator (Implied)

//Op Codes (Stack Operations)
#define TSX     ((Byte) 0xBA)  //Transfer Stack Pointer to x
#define TXS     ((Byte) 0x9A)  //Transfer x to Stack Pointer
#define PHA     ((Byte) 0x48)  //Push Accumulator on to Stack
#define PHP     ((Byte) 0x08)  //Push Processor Status on to Stack
#define PLA     ((Byte) 0x68)  //Pull Accumulator from Stack
#define PLP     ((Byte) 0x28)  //Pull Processor Status from Stack

//Op Codes (Logical)
#define AND_im  ((Byte) 0x29) //Logical AND (Immediate Mode)
#define AND_zp  ((Byte) 0x25) //Logical AND (Zero Page)
#define AND_zpx ((Byte) 0x35) //Logical AND (Zero Page, x)
#define AND_ab  ((Byte) 0x2D) //Logical AND (Absolute Mode)
#define AND_abx ((Byte) 0x3D) //Logical AND (Absolute Mode, x)
#define AND_aby ((Byte) 0x39) //Logical AND (Absolute Mode, y)
#define AND_inx ((Byte) 0x21) //Logical AND (Indirect Mode, x)
#define AND_iny ((Byte) 0x31) //Logical AND (Indirect Mode, y)

#define EOR_im  ((Byte) 0x49) //Exclusive OR (Immediate Mode)
#define EOR_zp  ((Byte) 0x45) //Exclusive OR (Zero Page)
#define EOR_zpx ((Byte) 0x55) //Exclusive OR (Zero Page, x)
#define EOR_ab  ((Byte) 0x4D) //Exclusive OR (Absolute Mode)
#define EOR_abx ((Byte) 0x5D) //Exclusive OR (Absolute Mode, x)
#define EOR_aby ((Byte) 0x59) //Exclusive OR (Absolute Mode, y)
#define EOR_inx ((Byte) 0x41) //Exclusive OR (Indirect Mode, x)
#define EOR_iny ((Byte) 0x51) //Exclusive OR (Indirect Mode, y)

#define ORA_im  ((Byte) 0x09) //Inclusive OR (Immediate mode)
#define ORA_zp  ((Byte) 0x05) //Inclusive OR (Zero Page)
#define ORA_zpx ((Byte) 0x15) //Inclusive OR (Zero Page, x)
#define ORA_ab  ((Byte) 0x0D) //Inclusive OR (Absolute Mode)
#define ORA_abx ((Byte) 0x1D) //Inclusive OR (Absolute Mode, x)
#define ORA_aby ((Byte) 0x19) //Inclusive OR (Absolute Mode, y)
#define ORA_inx ((Byte) 0x01) //Inclusive OR (Indirect Mode, x)
#define ORA_iny ((Byte) 0x11) //Inclusive OR (Indirect Mode, y)

#define BIT_zp  ((Byte) 0x24) //Bit Test (Zero Page)
#define BIT_ab  ((Byte) 0x2C) //Bit Test (Absolute Mode)

//Op Codes (Arithmetic)


//Op Codes (Increments & Decrements)
#define INC_zp  ((Byte) 0xE6)  //Increment Memory (Zero Page)
#define INC_zpx ((Byte) 0xF6)  //Increment Memory (Zero Page, x)
#define INC_ab  ((Byte) 0xEE)  //Increment Memory (Absolute Mode)
#define INC_abx ((Byte) 0xFE)  //Increment Memory (Absolute Mode, x)

#define INX     ((Byte) 0xE8)  //Increment x Register (Implied)
#define INY     ((Byte) 0xC8)  //Increment y Register (Implied)

#define DEC_zp  ((Byte) 0xC6)  //Decrement Memory (Zero Page)
#define DEC_zpx ((Byte) 0xD6)  //Decrement Memory (Zero Page, x)
#define DEC_ab  ((Byte) 0xCE)  //Decrement Memory (Absolute Mode)
#define DEC_abx ((Byte) 0xC6)  //Decrement Memory (Absolute Memory, x)

#define DEX     ((Byte) 0xCA)  //Decrement x Register (Implied)
#define DEY     ((Byte) 0x88)  //Decrement y Register (Implied)

//Op Codes (Shifts)

//Op Codes (Jumps & Calls)
#define JSR     ((Byte) 0x20)  //Jump to sub-Routine (Absolute Mode)

#define JMP_ab  ((Byte) 0x4C)  //Jump (Absolute Mode)
#define JMP_in  ((Byte) 0x6C)  //Jump (Indirect Mode)

#define RTS     ((Byte) 0x60)  //Return from sub-Routine (Implied)

//Op Codes (Branches)
#define BCC     ((Byte) 0x90)  //Branch if Carry Clear (Relative)
#define BCS     ((Byte) 0xB0)  //Branch if Carry Set (Relative)
#define BEQ     ((Byte) 0xF0)  //Branch if Equal (Relative)
#define BMI     ((Byte) 0x30)  //Branch if Minus (Relative)
#define BNE     ((Byte) 0xD0)  //Branch if Not Equal (Relative)
#define BPL     ((Byte) 0x10)  //Branch if Positive (Relative)
#define BVC     ((Byte) 0x50)  //Branch if Overflow Clear (Relative)
#define BVS     ((Byte) 0x70)  //Branch if Overflow Set (Relative)

//Op Codes (Status Flag Changes)
#define CLC     ((Byte) 0x18)  //Clear Carry Flag (Implied)
#define CLD     ((Byte) 0xD8)  //Clear Decimal Mode (Implied)
#define CLI     ((Byte) 0x58)  //Clear Interrupt Disable (Implied)
#define CLV     ((Byte) 0xB8)  //Clear Overflow Flag (Implied)
#define SEC     ((Byte) 0x38)  //Set Carry Flag (Implied)
#define SED     ((Byte) 0xF8)  //Set Decimal Flag (Implied)
#define SEI     ((Byte) 0x78)  //Set Interrupt Disable (Implied)

//Op Codes (System Functions)
#define BRK     ((Byte) 0x00)  //Force Interrupt (Implied)
#define NOP     ((Byte) 0xEA)  //No Operation (Implied)
#define RTI     ((Byte) 0x40)  //Return from Interrupt (Implied)

u32 numCycles = 0;

void reset(struct CPU *pCpu, struct Memory *pMemory);

Byte fetchInstructionByte(Word *pCounter, struct Memory *pMemory, u32 *pCycles);

Byte readInstruction(Byte address, struct Memory *pMemory, u32 *pCycles);

Word fetchInstructionWord(Word *pCounter, struct Memory *pMemory, u32 *pCycles);

void writeWord(Word data, struct Memory *pMemory, u32 address, u32 *pCycles);

void exec(struct CPU *pCpu, struct Memory *pMemory, u32 *pCycles);

#endif //CPU_SIM_SIMULATIONS_H
