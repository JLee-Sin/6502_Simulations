#include <stdio.h>
#include "Memory.h"

//Initializes pMemory by clearing data
void initMemory(struct Memory *pMemory) {
    printf("Initializing Memory...\n");
    for(u32 i = 0; i < Max_Mem; i++) {
        pMemory->data[i] = 0;
    }
    printf("Memory Initialized to 0\n");
}
