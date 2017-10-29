// NOTES
// --Implement the updateTime method (this will be hardcoded)

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "iec_std_lib.h"

// ===== Defines ===== //
// External variable linkage
#define __LOCATED_VAR(type, name, ...) type __##name; type *name = &__##name;
#include "LOCATED_VARIABLES.h"

// Constants
#define NUM_IEC_TYPES 15

typedef enum
{
	IEC_BOOL_T,

	IEC_SINT_T,
	IEC_INT_T,
	IEC_DINT_T,
	IEC_LINT_T,

	IEC_USINT_T,
	IEC_UINT_T,
	IEC_UDINT_T,
	IEC_ULINT_T,

	IEC_BYTE_T,
	IEC_WORD_T,
	IEC_DWORD_T,
	IEC_LWORD_T,

	IEC_REAL_T,
	IEC_LREAL_T
} IEC_TYPE;

// ===== Union ===== //
typedef union
{
	uint8_t  iec_uint8;
	uint16_t iec_uint16;
	uint32_t iec_uint32;
	uint64_t iec_uint64;

	int8_t   iec_int8;
	int16_t  iec_int16;
	int32_t  iec_int32;
	int64_t  iec_int64;

	float    iec_single;
	double   iec_double;
} iec_type_t;

// ===== Variables ===== //
TIME __CURRENT_TIME; // NOTE this is an necessary variable

// ===== Static variables ===== //
static uint32_t tick = 0;

static void ***inputs;
static void ***outputs;

extern const size_t inputs_lens[NUM_IEC_TYPES];
extern const size_t outputs_lens[NUM_IEC_TYPES];

// ===== External ===== //
extern void config_init__();
extern void config_run__(unsigned long tick);

/***** Functions declarations *****/
void hello_world(); 

// Public functions
void config_run();

void init_variables();
iec_type_t read_variable(size_t type, size_t idx);
void set_variable(iec_type_t in, size_t type, size_t idx);

// Private functions
bool _check_index(const size_t *lens, size_t type, size_t index);

/***** Function definitions *****/
void hello_world()
{
    printf("Hello World\n");
}

void config_run()
{
    config_run__(tick++);
}

// TODO write the function comments and put into interface.h
void set_variable(iec_type_t in, size_t type, size_t idx)
{
	// Check if inbounds
	if (!_check_index(inputs_lens, type, idx))
	{
		return;
	}

	// Set element in array
	switch ((IEC_TYPE)type)
	{
		case IEC_BOOL_T:
			*((uint8_t*)inputs[type][idx]) = in.iec_uint8;
			break;
		case IEC_SINT_T:
			*((int8_t*)inputs[type][idx]) = in.iec_int8;
			break;
		case IEC_INT_T:
			*((int16_t*)inputs[type][idx]) = in.iec_int16;
			break;
		case IEC_DINT_T: 
			*((int32_t*)inputs[type][idx]) = in.iec_int32;
			break;
		case IEC_LINT_T:
			*((int64_t*)inputs[type][idx]) = in.iec_int64;
			break;
		case IEC_USINT_T:
			*((uint8_t*)inputs[type][idx]) = in.iec_uint8;
			break;
		case IEC_UINT_T:
			*((uint16_t*)inputs[type][idx]) = in.iec_uint16;
			break;
		case IEC_UDINT_T:
			*((uint32_t*)inputs[type][idx]) = in.iec_uint32;
			break;
		case IEC_ULINT_T:
			*((uint64_t*)inputs[type][idx]) = in.iec_uint64;
			break;
		case IEC_BYTE_T:
			*((uint8_t*)inputs[type][idx]) = in.iec_uint8;
			break;
		case IEC_WORD_T:
			*((uint16_t*)inputs[type][idx]) = in.iec_uint16;
			break;
		case IEC_DWORD_T:
			*((uint32_t*)inputs[type][idx]) = in.iec_uint32;
			break;
		case IEC_LWORD_T:
			*((uint64_t*)inputs[type][idx]) = in.iec_uint64;
			break;
		case IEC_REAL_T:
			*((float*)inputs[type][idx]) = in.iec_single;
			break;
		case IEC_LREAL_T:
			*((double*)inputs[type][idx]) = in.iec_double;
			break;
		default:
			printf("Invalid type.");
			break;
	}
}

// TODO write the function comments and put into interface.h
iec_type_t read_variable(size_t type, size_t idx)
{
	iec_type_t t;

	// Check if inbounds
	if (!_check_index(outputs_lens, type, idx))
	{
		return t;
	}

	// Read element in array
	switch ((IEC_TYPE)type)
	{
		case IEC_BOOL_T:
			t.iec_uint8 = *((uint8_t*)outputs[type][idx]);
			break;
		case IEC_SINT_T:
			t.iec_int8 = *((int8_t*)outputs[type][idx]);
			break;
		case IEC_INT_T:
			t.iec_int16 = *((int16_t*)outputs[type][idx]);
			break;
		case IEC_DINT_T:
			t.iec_int32 = *((int32_t*)outputs[type][idx]);
			break;
		case IEC_LINT_T:
			t.iec_int64 = *((int64_t*)outputs[type][idx]);
			break;
		case IEC_USINT_T:
			t.iec_uint8 = *((uint8_t*)outputs[type][idx]);
			break;
		case IEC_UINT_T:
			t.iec_uint16 =  *((uint16_t*)outputs[type][idx]);
			break;
		case IEC_UDINT_T:
			t.iec_uint32 = *((uint32_t*)outputs[type][idx]);
			break;
		case IEC_ULINT_T:
			t.iec_uint64 = *((uint64_t*)outputs[type][idx]);
			break;
		case IEC_BYTE_T:
			t.iec_uint8 = *((uint8_t*)outputs[type][idx]);
			break;
		case IEC_WORD_T:
			t.iec_uint16 = *((uint16_t*)outputs[type][idx]);
			break;
		case IEC_DWORD_T:
			t.iec_uint32 = *((uint32_t*)outputs[type][idx]);
			break;
		case IEC_LWORD_T:
			t.iec_uint64 = *((uint64_t*)outputs[type][idx]);
			break;
		case IEC_REAL_T:
			t.iec_single = *((float*)outputs[type][idx]);
			break;
		case IEC_LREAL_T:
			t.iec_double = *((double*)outputs[type][idx]);
			break;
		default:
			printf("Invalid type.");
			break;
	}

	return t;
}

bool _check_index(const size_t *lens, size_t type, size_t idx)
{
	// Check if lens is valid
	if (lens == NULL)
	{
		return false;
	}

	// Check if type is inbounds
	if (!(type < NUM_IEC_TYPES))
	{
		return false;
	}

	// Check if idx in inbounds
	if (!(idx < lens[type]))
	{
		return false;
	}

	return true;
}