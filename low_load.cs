using System;
using System.Diagnostics;

class LowLoad
{
    static void Main(string[] args)
    {
        long sum = 0;
        long n = 984_600_000;

        Console.WriteLine("Program starting...");

        var start = Stopwatch.GetTimestamp();
        Console.WriteLine($"Start time: {(double)start / Stopwatch.Frequency}");

        var sw = Stopwatch.StartNew();

        for (long i = 1; i <= n; i++)
        {
            sum += i;
        }

        sw.Stop();
        var end = Stopwatch.GetTimestamp();

        Console.WriteLine($"End time: {(double)end / Stopwatch.Frequency}");
        Console.WriteLine($"Time elapsed: {sw.Elapsed.TotalSeconds:F8} seconds");
        Console.WriteLine($"Sum: {sum}");

        Console.Out.Flush();
    }
}
