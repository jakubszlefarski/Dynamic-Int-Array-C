#ifndef ARRAY_H
#define ARRAY_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct 
{
    int *data;
    int size;
} IntArray;

enum OPERATION{
    QUIT,
    SUM,
    APPEND,
    POP,
    SORT,
    UNDEFINED
};

enum MODE{
    INSERT,
    DELETE
};

typedef struct Args{
    int value;
    int index;
}Args;

int inttoenum(int intinput);
void printarray(IntArray array);
void sumarray(IntArray array);
void pushpull(IntArray *array, int index, int value, enum MODE mode);
void append(IntArray *array, struct Args *args);
void pop(IntArray *array, struct Args *args);
void swap(IntArray *array, int currentindex);
void sortarray(IntArray *array);
struct Args* getargs(enum MODE mode, IntArray *array);

#endif