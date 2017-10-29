#include "Wrapper.h"

Wrapper::Wrapper() : _impl(new Interface())
{
}

Wrapper::~Wrapper()
{
	destroy();
}

Wrapper::!Wrapper()
{
	destroy();
}

void Wrapper::print_hello()
{
	_impl->print_hello();
}

generic <typename T>
void Wrapper::print_variable(T t, size_t idx)
{
	if (t->GetType() == IEC_DINT::typeid)
	{
		_impl->print_variable(safe_cast<IEC_DINT>(t), idx);
	}
}

void Wrapper::destroy() 
{
	if (_impl != nullptr)
	{
		delete _impl;
		_impl = nullptr;
	}
}

