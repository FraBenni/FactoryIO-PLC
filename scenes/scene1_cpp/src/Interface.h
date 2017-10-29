#pragma once

// TODO create a updateTimer function (glueVars.cpp)

#include <vector>

// ====== Defines ====== //
// Miscelaneous
#define DEBUGGING 1

// ====== Externs ====== //




// ===== Variables ===== //
TIME __CURRENT_TIME; // Required variable used by ladder code

// ===== Class declaration ===== //
class Interface
{
public:
	Interface();

	void config_init();
	void config_run();
	void init_variables();

	template <typename T> T read_variable(T type, size_t idx);
	template <typename T> void set_variable(T input, size_t idx);

private:
	uint32_t tick;
	
	std::vector<IEC_BOOL*> bool_inputs;
	std::vector<IEC_BOOL*> bool_outputs;
};

// ===== Class partial definition ====== //


// Read variable templates
template <typename T> T Interface::read_variable(T type, size_t idx)
{ }

template <> IEC_BOOL Interface::read_variable(IEC_BOOL type, size_t idx)
{
	return *bool_outputs.at(idx);
}

// Set variable templates
template <typename T> void Interface::set_variable(T input, size_t idx)
{ }

template <> void Interface::set_variable(IEC_BOOL input, size_t idx)
{
	*bool_inputs.at(idx) = input;
}
