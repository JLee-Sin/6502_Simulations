#include <stdio.h>
#include "CPU.h"
#include "Memory.h"
#include "main.h"

//Reset/Boot up Sequence
void reset(struct CPU *pCpu, struct Memory *pMemory) {
    printf("Beginning Reset Sequence\n");
    pCpu->pCounter = 0xFFFC;
    pCpu->sPointer = 0x0100;
    Byte flags[] = {pCpu->C, pCpu->Z, pCpu->I, pCpu->D, pCpu->B, pCpu->O, pCpu->N};
    clearFlags(flags);
    Byte registers[] = {pCpu->a, pCpu->x, pCpu->y};
    clearRegisters(registers);
    initMemory(pMemory);
    printf("Reset Complete\n\n");
}

Byte fetchInstruction(Word *pCounter, struct Memory *pMemory, u32 *pCycles){
    Byte data = pMemory->data[*pCounter];
    *pCounter += 1;
    *pCycles  -= 1;
    printf("pCounter: %d\n", *pCounter);
    return data;
}

Byte readInstruction(Byte address, struct Memory *pMemory, u32 *pCycles) {
    Byte data = pMemory->data[address];
    *pCycles  -= 1;
    return data;
}

void exec(struct CPU *pCpu, struct Memory *pMemory, u32 *pCycles) {
    Word *pCounter = &pCpu->pCounter;
    printf("Executing %d cycles, starting at %d in memory...\n", *pCycles, *pCounter);
    while(*pCycles > 0) {
        printf("\n");
        Byte instruction = fetchInstruction(pCounter, pMemory, pCycles);
        printf("Instruction: %d\n", instruction);
        printf("pCounter: %d\n", *pCounter);
        Byte value;
        switch(instruction) {
            case JSR:
                break;
            case LDA_im:
                printf("Load Accumulator (Immediate mode)\n");
                value   = fetchInstruction(pCounter, pMemory, pCycles);
                pCpu->a = value;
                printf("Value loaded to Accumulator: %d\n", pCpu->a);
                if(pCpu->a == 0) {
                    pCpu->Z = 1;
                    printf("Set Zero flag\n");
                }
                if((pCpu->a & 0b10000000) > 0) {
                    pCpu->N = 1;
                    printf("Set Negative flag\n");
                }
                break;
            case LDA_zp:
                printf("Load Accumulator (Zero Page)\n");
                value   = fetchInstruction(pCounter, pMemory, pCycles);
                pCpu->a = readInstruction(value, pMemory, pCycles);
                printf("Value loaded to Accumulator: %d\n", pCpu->a);
                if(pCpu->a == 0) {
                    pCpu->Z = 1;
                    printf("Set Zero flag\n");
                }
                if((pCpu->a & 0b10000000) > 0) {
                    pCpu->N = 1;
                    printf("Set Negative flag\n");
                }
                break;
            case LDA_zpx:
                printf("Load Accumulator (Zero Page, x)\n");
                value   = fetchInstruction(pCounter, pMemory, pCycles);
                value += pCpu->x;
                pCycles -= 1;
                pCpu->a = readInstruction(value, pMemory, pCycles);
                printf("Value loaded to Accumulator: %d\n", pCpu->a);
                if(pCpu->a == 0) {
                    pCpu->Z = 1;
                    printf("Set Zero flag\n");
                }
                if((pCpu->a & 0b10000000) > 0) {
                    pCpu->N = 1;
                    printf("Set Negative flag\n");
                }
                break;
            case LDX_im:
                printf("Load X Register (Immediate mode)\n");
                value   = fetchInstruction(pCounter, pMemory, pCycles);
                pCpu->x = value;
                printf("Value loaded to Register: %d\n", pCpu->x);
                if(pCpu->x == 0) {
                    pCpu->Z = 1;
                    printf("Set Zero flag\n");
                }
                if((pCpu->x & 0b10000000) > 0) {
                    pCpu->N = 1;
                    printf("Set Negative Flag\n");
                }
                break;
            case LDY_im:
                printf("Load X Register (Immediate mode)\n");
                value   = fetchInstruction(pCounter, pMemory, pCycles);
                pCpu->y = value;
                printf("Value loaded to Register: %d\n", pCpu->y);
                if(pCpu->y == 0) {
                    pCpu->Z = 1;
                    printf("Set Zero flag\n");
                }
                if((pCpu->y & 0b10000000) > 0) {
                    pCpu->N = 1;
                    printf("Set Negative Flag\n");
                }
                break;
            default:
                printf("No Instruction was received\n");
                break;
        }
    }
    printf("\nExecution Complete\n\n");
}

int main() {
    printf("Booting...\n\n");
    struct Memory memory;
    struct CPU cpu;
    reset(&cpu, &memory);

    //Hardcoded Testing

    //End Test
    if(numCycles != 0) {
        exec(&cpu, &memory, &numCycles);
    }
    printf("Terminating");

    return 0;
}
