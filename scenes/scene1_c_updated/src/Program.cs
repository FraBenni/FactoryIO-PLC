using System;
using System.Threading;

using EngineIO;

class Program
{
    public static int CycleTime = 8;

    static void Main(string[] args)
    {
        //MemoryBit used to switch FACTORY I/O between edit and run mode
        MemoryBit start = MemoryMap.Instance.GetBit(MemoryMap.BitCount - 16, MemoryType.Output);

        //MemoryBit used to detect if FACTORY I/O is edit or run mode
        MemoryBit running = MemoryMap.Instance.GetBit(MemoryMap.BitCount - 16, MemoryType.Input);

        //Forcing a rising edge on the start MemoryBit so FACTORY I/O can detect it
        SwitchToRun(start);
        
        Interface inter = new Interface();

        Console.WriteLine("Running. Press Escape to shutdown...");

        while (!(Console.KeyAvailable && (Console.ReadKey(false).Key == ConsoleKey.Escape)))
        {
            //Update the memory map before executing the controller
            MemoryMap.Instance.Update();

            if (running.Value)
            {
                inter.PLCCycle();
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



