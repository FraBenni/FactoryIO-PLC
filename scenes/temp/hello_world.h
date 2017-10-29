#include <stdint.h>
#include <stdlib.h>

typedef union 
{
    uint8_t UINT8;
    int     INT;
    float   FLOAT;
} TYPE;

void hello_world();
TYPE read_variable(size_t type, size_t idx);
void set_variable(TYPE input, size_t type, size_t idx);
