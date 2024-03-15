#include <stdio.h>
#include "CPU.h"

//clears all the flags passed to it in the form of an array
void clearFlags(Byte *pflags[]) {
    printf("Clearing Flags...\n");
    int size = sizeof(pflags) / sizeof(pflags[0]);
    for(int i = 0; i < size; i++) {
        pflags[i] = 0;
    }
    printf("Flags Cleared\n");
}

//clears all the registers passed to it in the form of an array
void clearRegisters(Byte *pRegisters[]) {
    printf("Clearing Registers..\n");
    int size = sizeof(pRegisters) / sizeof(pRegisters[0]);
    for(int i = 0; i < size; i++) {
        pRegisters[i] = 0;
    }
    printf("Registers Cleared\n");
}

