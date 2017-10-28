﻿// TODO autogenerated

using System;
using System.Runtime.InteropServices;

using EngineIO;

namespace FT1
{
	[StructLayout(LayoutKind.Explicit)]
	public struct iec_type_t
	{
		[FieldOffset(0)] public System.Byte iec_uint8;
		[FieldOffset(0)] public System.UInt16 iec_uint16;
		[FieldOffset(0)] public System.UInt32 iec_uint32;
		[FieldOffset(0)] public System.UInt64 iec_uint64;

		[FieldOffset(0)] public System.SByte iec_int8;
		[FieldOffset(0)] public System.Int16 iec_int16;
		[FieldOffset(0)] public System.Int32 iec_int32;
		[FieldOffset(0)] public System.Int64 iec_int64;

		[FieldOffset(0)] public System.Single iec_single;
		[FieldOffset(0)] public System.Double iec_double;
	}

	public class FT_Con1
	{
		// TODO consider making the dll imports all private rather than public

		// ===== DLL imports ===== //
		[DllImport("./ft-con1.dll")]
		public static extern void init_variables();

		[DllImport("./ft-con1.dll")]
		public static extern iec_type_t read_variable(ulong type, ulong idx);

		[DllImport("./ft-con1.dll")]
		public static extern void set_variable(iec_type_t input, ulong type, ulong idx);

		[DllImport("./ft-con1.dll")]
		public static extern void config_run();

		// ===== Factory I/O variables ===== //
		public MemoryBit C1_startIR;
		public MemoryBit C1_endIR;

		public MemoryBit C1_motor;
		public MemoryBit R1_fwd_motor;

		public FT_Con1()
		{
			// Inputs
			 C1_startIR= MemoryMap.Instance.GetBit("C1_startIR", MemoryType.Input);
			 C1_endIR = MemoryMap.Instance.GetBit("C1_endIR", MemoryType.Input);

			 // Outputs
			 C1_motor = MemoryMap.Instance.GetBit("C1_motor", MemoryType.Output);
			 R1_fwd_motor = MemoryMap.Instance.GetBit("R1_fwd_motor", MemoryType.Output);

			init_variables();
		}

		public void PLCCycle()
		{
			ReadInputs();
			config_run();
			SetOutputs();
		}

		private void ReadInputs()
		{
			iec_type_t iec_type = new iec_type_t();

			// Sensor
			iec_type.iec_uint8 = C1_startIR.Value ? (byte)1 : (byte)0;
			set_variable(iec_type, 0, 0);

			iec_type.iec_uint8 = C1_endIR.Value ? (byte)1 : (byte)0;
			set_variable(iec_type, 0, 1);
		}

		private void ConfigRun()
		{
			config_run();
		}

		// FIXME
		private void SetOutputs()
		{
			iec_type_t iec_type = new iec_type_t();

			// Conveyor
			iec_type = read_variable(0, 0);
			C1_motor.Value = (iec_type.iec_uint8 == 0) ? true : false;

			iec_type = read_variable(0, 1);
			R1_fwd_motor.Value = (iec_type.iec_uint8 == 0) ? true : false;

		}

		// TODO create an enumeration for all the different types
		//      and create an encoder/decoder that automatically gets the right value

	}
}