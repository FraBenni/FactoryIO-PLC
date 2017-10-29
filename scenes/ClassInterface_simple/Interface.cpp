#include <iostream>

#include "Interface.h"

void Interface::print_hello()
{
	std::cout << "Hello World!" << std::endl;
}

template <class T>
void Interface::print_variable(T t, size_t idx)
{ }

template <>
void Interface::print_variable(int i, size_t idx)
{
	std::cout << "Integer: " << i << std::endl;
}