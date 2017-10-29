#include "Wrapper.h"

Wrapper::Wrapper() : _interface(new Interface())
{ }

Wrapper::~Wrapper()
{
	destroy();
}

Wrapper::!Wrapper()
{
	destroy();
}

Wrapper::config_init()
{
	_interface->config_init();
}

Wrapper::config_run()
{
	_interface->config_run();
}

generic <typename T> T Wrapper::read_variable(T type, size_t idx)
{
	System::Type t = type->GetType();
	if (t == IEC_BOOL::typeid)
		return _interface->read_variable(safe_cast<IEC_BOOL>(t), idx);
	else if (t == IEC_SINT::typeid)
		return _interface->read_variable(safe_cast<IEC_SINT>(t), idx);
	else if (t == IEC_INT)::typeid
		return _interface->read_variable(safe_cast<IEC_INT>(t), idx);
	else if (t == IEC_DINT::typeid)
		return _interface->read_variable(safe_cast<IEC_DINT>(t), idx);
	else if (t == IEC_LINT::typeid)
		return _interface->read_variable(safe_cast<IEC_LINT>(t), idx);
	else if (t == IEC_USINT::typeid)
		return _interface->read_variable(safe_cast<IEC_USINT>(t), idx);
	else if (t == IEC_UINT::typeid)
		return _interface->read_variable(safe_cast<IEC_UINT>(t), idx);
	else if (t == IEC_UDINT::typeid)
		return _interface->read_variable(safe_cast<IEC_UDINT>(t), idx);
	else if (t == IEC_ULINT::typeid)
		return _interface->read_variable(safe_cast<IEC_ULINT>(t), idx);
	else if (t == IEC_BYTE::typeid)
		return _interface->read_variable(safe_cast<IEC_BYTE>(t), idx);
	else if (t == IEC_WORD::typeid)
		return _interface->read_variable(safe_cast<IEC_WORD>(t), idx);
	else if (t == IEC_DWORD::typeid)
		return _interface->read_variable(safe_cast<IEC_DWORD>(t), idx);
	else if (t == IEC_LWORD::typeid)
		return _interface->read_variable(safe_cast<IEC_LWORD>(t), idx);
	else if (t == IEC_REAL::typeid)
		return _interface->read_variable(safe_cast<IEC_REAL>(t), idx);
	else if (t == IEC_LREAL::typeid)
		return _interface->read_variable(safe_cast<IEC_LREAL>(t), idx);
}

generic <typename T> T Wrapper::set_variable(T type, size_t idx)
{
	System::Type t = type->GetType();
	if (t == IEC_BOOL::typeid)
		_interface->set_variable(safe_cast<IEC_BOOL>(t), idx);
	else if (t == IEC_SINT::typeid)
		_interface->set_variable(safe_cast<IEC_SINT>(t), idx);
	else if (t == IEC_INT)::typeid
		_interface->set_variable(safe_cast<IEC_INT>(t), idx);
	else if (t == IEC_DINT::typeid)
		_interface->set_variable(safe_cast<IEC_DINT>(t), idx);
	else if (t == IEC_LINT::typeid)
		_interface->set_variable(safe_cast<IEC_LINT>(t), idx);
	else if (t == IEC_USINT::typeid)
		_interface->set_variable(safe_cast<IEC_USINT>(t), idx);
	else if (t == IEC_UINT::typeid)
		_interface->set_variable(safe_cast<IEC_UINT>(t), idx);
	else if (t == IEC_UDINT::typeid)
		_interface->set_variable(safe_cast<IEC_UDINT>(t), idx);
	else if (t == IEC_ULINT::typeid)
		_interface->set_variable(safe_cast<IEC_ULINT>(t), idx);
	else if (t == IEC_BYTE::typeid)
		_interface->set_variable(safe_cast<IEC_BYTE>(t), idx);
	else if (t == IEC_WORD::typeid)
		_interface->set_variable(safe_cast<IEC_WORD>(t), idx);
	else if (t == IEC_DWORD::typeid)
		_interface->set_variable(safe_cast<IEC_DWORD>(t), idx);
	else if (t == IEC_LWORD::typeid)
		_interface->set_variable(safe_cast<IEC_LWORD>(t), idx);
	else if (t == IEC_REAL::typeid)
		_interface->set_variable(safe_cast<IEC_REAL>(t), idx);
	else if (t == IEC_LREAL::typeid)
		_interface->set_variable(safe_cast<IEC_LREAL>(t), idx);
}

void destroy()
{
	if (_interface != nullptr)
	{
		delete _interface;
		_interface = nullptr;
	}
}