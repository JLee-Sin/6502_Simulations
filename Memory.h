//
// Created by jayle on 3/15/2024.
//

#ifndef CPU_SIM_MEMORY_H
#define CPU_SIM_MEMORY_H

typedef unsigned char Byte;
typedef unsigned short Word;
typedef unsigned int u32;

//Max Amount of memory
#define Max_Mem ((u32) (1024*64))

struct Memory {
    Byte data[Max_Mem];
};

void initMemory(struct Memory *pMemory);



#endif //CPU_SIM_MEMORY_H
