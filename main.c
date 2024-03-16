#include "simulations.c"
#include "CPU.c"
#include "Memory.c"

int main() {
    printf("\nBooting...\n\n");
    struct Memory memory;
    struct CPU cpu;
    reset(&cpu, &memory);

    //Hardcoded Testing
    //End Test

    if(numCycles != 0) {
        exec(&cpu, &memory, &numCycles);
    }
    printf("Terminating\n");

    return 0;
}


