cmake_minimum_required(VERSION 3.10)
project(DynamicIntArray C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(DynamicIntArrayProgram main.c array.c)