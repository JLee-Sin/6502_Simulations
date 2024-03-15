cmake_minimum_required(VERSION 3.20)
project(CPU_Sim C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(CPU_Sim
        main.c)
