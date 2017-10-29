#pragma once

class Interface
{
public:
	void print_hello();

	template <class T>
	void print_variable(T t, size_t idx);
};