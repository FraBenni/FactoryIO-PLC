#pragma once

#include "Interface.h"

using IEC_DINT = System::Int32;

public ref class Wrapper
{
public:
	Wrapper();
	~Wrapper();
	!Wrapper();

	void print_hello();
	generic <typename T>
	void print_variable(T t, size_t idx);
	void destroy();

private:
	Interface* _impl;
};