using System;
using System.Threading;

using EngineIO;

class Program
{
    public static int CycleTime = 500;

    static void Main(string[] args)
    {
        //MemoryBit used to switch FACTORY I/O between edit and run mode
        MemoryBit start = MemoryMap.Instance.GetBit(MemoryMap.BitCount - 16, MemoryType.Output);

        //MemoryBit used to detect if FACTORY I/O is edit or run mode
        MemoryBit running = MemoryMap.Instance.GetBit(MemoryMap.BitCount - 16, MemoryType.Input);

        //Forcing a rising edge on the start MemoryBit so FACTORY I/O can detect it
        SwitchToRun(start);
        
        FT1.FT_Con1 ft_con1 = new FT1.FT_Con1();
        FT2.FT_Con2 ft_con2 = new FT2.FT_Con2();
        FT3.FT_Con3 ft_con3 = new FT3.FT_Con3();
        FT4.FT_Con4 ft_con4 = new FT4.FT_Con4();

        Console.WriteLine("Running. Press Escape to shutdown...");

        while (!(Console.KeyAvailable && (Console.ReadKey(false).Key == ConsoleKey.Escape)))
        {
            //Update the memory map before executing the controller
            MemoryMap.Instance.Update();

            if (running.Value)
            {
                ft_con1.PLCCycle();
                ft_con2.PLCCycle();
                ft_con3.PLCCycle();
                ft_con4.PLCCycle();
            }

            Thread.Sleep(CycleTime);
        }

        Shutdown(start);
    }

    static void SwitchToRun(MemoryBit start)
    {
        start.Value = false;
        MemoryMap.Instance.Update();
        Thread.Sleep(500);

        start.Value = true;
        MemoryMap.Instance.Update();
        Thread.Sleep(500);
    }

    static void Shutdown(MemoryBit start)
    {
        start.Value = false;

        MemoryMap.Instance.Update();
        MemoryMap.Instance.Dispose();
    }
}



