using System;
using System.Runtime.InteropServices;

[StructLayout(LayoutKind.Explicit)]
struct TYPE
{
    [FieldOffset(0)] public System.Byte uint8_t;
    [FieldOffset(0)] public System.Int32 int_t;
    [FieldOffset(0)] public System.Single float_t;
}

class Test 
{
    [DllImport("./hello_world.dll")]
    public static extern void hello_world();

    [DllImport("./hello_world.dll")]
    public static extern TYPE read_variable(ulong type, ulong idx);

    [DllImport("./hello_world.dll")]
    public static extern void set_variable(TYPE input, ulong type, ulong idx);

    [DllImport("./hello_cpp.dll")]
    public static extern void hello_cpp();


    static void Main() 
    {
        hello_world();

        hello_cpp();

        TYPE t = new TYPE();
        t.uint8_t = 1;
        read_variable(0, 0);
        set_variable(t, 0, 0);
        read_variable(0, 0);

        t.float_t = 3.753f;
        set_variable(t, 2, 0);
        t = read_variable(2, 0);

        Console.WriteLine(t.float_t);
    }
}
