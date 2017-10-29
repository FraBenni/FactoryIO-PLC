#pragma once

#include "Interface.h"

// ===== IEC types ===== //
using IEC_BOOL = System::Byte;

using IEC_SINT = System::SByte;
using IEC_INT = System::Int16;
using IEC_DINT = System::Int32;
using IEC_LINT = System::Int64;

using IEC_USINT = System::Byte;
using IEC_UINT = System::UInt16;
using IEC_UDINT = System::UInt32;
using IEC_ULINT = System::UInt64;

using IEC_BYTE = System::Byte;
using IEC_WORD = System::UInt16;
using IEC_DWORD = System::UInt32;
using IEC_LWORD = System::UInt64;

using IEC_REAL = System::Single;
using IEC_LREAL = System::Double;

// ===== Wrapper declaration ===== //
public ref class Wrapper
{
public:
	Wrapper();
	~Wrapper();
	!Wrapper();

	void config_init();
	void config_run();

	generic <typename T> T read_variable(T type, size_t idx);
	generic <typename T> void set_variable(T type, size_t idx);

private:
	Interface* _interface;

	void destroy();
};