#include <stdio.h>

#include "hello_world.h"

static TYPE arr[3][1] = {{0}, {0}, {0}};

void hello_world() 
{
    printf("Hello World!\n");
}

TYPE read_variable(size_t type, size_t idx)
{
    TYPE t;
    switch (type)
    {
        case 0:
            t = arr[0][idx];
            printf("uint8_t: %d\n", (int)t.UINT8);
            break;
        case 1:
            t = arr[1][idx];
            printf("int: %d\n", t.INT);
            break;
        case 2:
            t = arr[2][idx];
            printf("float: %g\n", t.FLOAT);
            break;
        default:
            printf("Invalid type.\n");
            break;
    }

    return t;
}

void set_variable(TYPE input, size_t type, size_t idx)
{
   arr[type][idx] = input;
}
