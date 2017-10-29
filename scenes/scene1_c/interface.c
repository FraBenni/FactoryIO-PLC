// NOTES
// --For now only set the inputs
// --To simplify generation, define split code across interface.c/.h
// --Consider template specialization and C++
// --Can make things that are auto-generated be put into an auto-gen.h file and
//     have it be included by interface.c/.h
//  --Implement the updateTime method (this will be hardcoded)

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "../lib/iec_std_lib.h"

/***** Enums *****/
//typedef enum type_t {DEAD, ALIVE} type;

/***** Defines *****/
// Miscellaneous
#define DEBUGGING 1

// External variable linkage
// NOTE this variable is used across multiple files
#define __LOCATED_VAR(type, name, ...) type __##name; type *name = &__##name;
#include "cc/LOCATED_VARIABLES.h"

// Variable I/O amounts
#define BOOL_INPUTS 1
#define BOOL_OUTPUTS 1

/***** Variables *****/
TIME __CURRENT_TIME; // NOTE this is an necessary variable

/***** Static variables *****/
static uint32_t tick = 0;

static IEC_BOOL *bool_inputs[BOOL_INPUTS];
static IEC_BOOL *bool_outputs[BOOL_OUTPUTS];

/***** Functions declarations *****/
// Public functions
void init_variables();
//void set_variable(int type, int index, int input);
void set_variable(int type, int index, int input);
void read_variable(int type, int index);
void hello_world(); 

extern void config_init__();
extern void config_run__(unsigned long tick);

void config_run();
void config_init();

// Private functions
bool _check_index(int type, int index);
bool _check_input(int type, char *input, void *value);

/***** Function definitions *****/

void hello_world()
{
    printf("Hello World\n");
}

void config_run()
{
    config_run__(tick++);
}

void config_init()
{
    config_init__();
}

// TODO write the function code
void init_variables()
{
    // Boolean variables
    bool_inputs[0] = __IX0_0; 
    bool_outputs[0] = __QX0_0;

    if (DEBUGGING)
        printf("Initiliazed variables\n");
}

// TODO write the function comments and put into interface.h
//void set_variable(int type, int index, char *input) 
void set_variable(int type, int index, int input) 
{
    // FIXME Hardcoded boolean for now
    void *value = malloc(sizeof(IEC_BOOL));

    // Check if valid inputs
    bool index_valid = _check_index(type, index);
    /*
    bool input_valid = _check_input(type, input, value);
    if (!index_valid || !input_valid)
    */
    if (!index_valid)
    {
        return;
    }

    switch (type) 
    {
        case 0:
            //*bool_inputs[index] = *((IEC_BOOL*)value);
            *bool_inputs[index] = input;
            break;
        default:
            if (DEBUGGING)
                printf("Unspecified type\n");
            break;
    }
}

// TODO write the function comments and put into interface.h
// FIXME this should be able to read either outputs or inputs
//     for now it can only read outputs
void read_variable(int type, int index) 
{
    bool index_valid = _check_index(type, index);    
    if (!index_valid)
    {
        return;
    }

    char *str = (char*)malloc(16 * sizeof(char));
    sprintf(str, "%d", *bool_outputs[index]);

    // FIXME
    if (DEBUGGING)
    {
        printf("%s, %d\n", str, *bool_inputs[0]);
    }
}


// TODO write the function comments and put into interface.h
bool _check_index(int type, int index)
{
    int len = 0;

    // Get corresponding length
    switch (type)
    {
        case 0:
            len = BOOL_INPUTS;
            break;
        default:
            if (DEBUGGING)
                printf("Unspecified type\n");
            break;
    }

    if (0 <= index && index < len) 
    { 
        return true;
    }

    return false;
}

// TODO write the function comments and put into interface.h
bool _check_input(int type, char *input, void *value) 
{
    /*
    switch (type)
    {
        case 0:
        {
            IEC_BOOL scan;
            if (sscanf(input, "%d", &scan) != 1)
            {
                if (DEBUGGING)
                    printf("Invalid input for IEC_BOOL\n");
                return false; 
            }

            //*((IEC_BOOL*)value) = (uint8_t)scan;
            break;
        }
        default:
            if (DEBUGGING)
                printf("Unspecified type\n");
            return false;
    }
    */

    return true;
}
