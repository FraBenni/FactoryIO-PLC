#include <stdio.h>

#include "../lib/iec_std_lib.h"

extern void hello_world();

extern void config_init();
extern void init_variables();

extern void config_run();
extern void read_variable(int type, int index);
extern void set_variable(int type, int index, int input);

int main()
{
    hello_world();

    // Initialization
    config_init();
    init_variables();
    read_variable(0, 0);

    // Cycle 1
    printf("Cycle 1\n");
    config_run();
    read_variable(0, 0);

    // Cycle 2
    printf("Cycle 2\n");
    set_variable(0, 0, 0);
    config_run();
    read_variable(0, 0);
    
    return 0;
}
