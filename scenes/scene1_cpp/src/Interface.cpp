#include "Interface.h"
#include "array_lens.h"

#include "../../lib/iec_std_lib.h"

// TODO make auto-generated

// Extern functions
extern "C"
{
	void config_init__();
	void config_run__(unsigned long tick);
}

// Extern variables
#define __LOCATED_VAR(type, name, ...) type __##name; type *name = &__##name;
#include "LOCATED_VARIABLES.h"

void Interface::config_init()
{
	config_init__();
}

void Interface::config_run()
{
	config_run__(tick++);
}

Interface::Interface() : tick(0)
{ 
	bool_inputs.reserve(IEC_BOOL_INPUTS);
	bool_outputs.reserve(IEC_BOOL_OUTPUTS);
}

void Interface::init_variables()
{
	// Inputs
	bool_inputs.at(0) = __IX0_0;

	// Outputs
	bool_outputs.at(0) = __QX0_0;
}

