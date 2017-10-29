#include "hello_world.h"

int main()
{
    hello_world();

    TYPE t;
    t.UINT8 = 10;

    set_variable(t, 0, 0);
    read_variable(0, 0);

    t.FLOAT = 4.87f;
    set_variable(t, 2, 0);
    read_variable(2, 0);
    
    return 0;
}
