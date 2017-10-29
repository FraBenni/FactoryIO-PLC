using System;
using System.Runtime.InteropServices;

class Scene1
{
    // Dummy function
    [DllImport("./interface.dll")]
    public static extern void hello_world();

    [DllImport("./interface.dll")]
    public static extern void init_variables();

    [DllImport("./interface.dll")]
    public static extern void config_init();

    [DllImport("./interface.dll")]
    public static extern void read_variable(int type, int index);


    [DllImport("./interface.dll")]
    public static extern void config_run();

    /*
    [DllImport("./interface.dll")]
    public unsafe static extern set_variable(
    //*/

    static void Main()
    {
        // Dummy
        hello_world();

        // Initialization
        config_init();
        init_variables();
        
        // Cycle 1
        read_variable(0, 0);
        config_run();
        read_variable(0, 0);

        // Cycle 2

    }
}
