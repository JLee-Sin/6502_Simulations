#include <stdio.h>
#include "CPU.h"

//clears all the pFlags passed to it in the form of an array
void clearFlags(struct CPU *pCpu) {
    printf("Clearing Flags...\n");
    pCpu->C = 0;
    pCpu->Z = 0;
    pCpu->I = 0;
    pCpu->D = 0;
    pCpu->B = 0;
    pCpu->O = 0;
    pCpu->N = 0;
    printf("Flags Cleared\n");
}

//clears all the pRegisters passed to it in the form of an array
void clearRegisters(struct CPU *pCpu) {
    printf("Clearing Registers..\n");
    pCpu->a = 0;
    pCpu->x = 0;
    pCpu->y = 0;
    printf("Registers Cleared\n");
}

