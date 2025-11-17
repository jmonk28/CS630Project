using System;
using System.Diagnostics;

class MediumLoad
{
    static void Swap(int[] arr, int i, int j)
    {
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }

    static int Partition(int[] arr, int low, int high)
    {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j < high; j++)
        {
            if (arr[j] <= pivot)
            {
                i++;
                Swap(arr, i, j);
            }
        }

        Swap(arr, i + 1, high);
        return i + 1;
    }

    static void QuickSort(int[] arr, int low, int high)
    {
        if (low < high)
        {
            int pi = Partition(arr, low, high);
            QuickSort(arr, low, pi - 1);
            QuickSort(arr, pi + 1, high);
        }
    }

    static void PrintArray(int[] arr)
    {
        Console.WriteLine($"First element: {arr[0]}");
        Console.WriteLine($"Last element: {arr[arr.Length - 1]}");
    }

    static void Main(string[] args)
    {
        long n = 1_000_000;
        int[] nums = new int[n];
        int min = 1, max = 100;

        Random rand = new Random();
        Console.WriteLine("Sorting 10000 random numbers from 1 to 100...");

        for (int i = 0; i < n; i++)
            nums[i] = rand.Next(min, max + 1);

        PrintArray(nums);

        var startTimestamp = Stopwatch.GetTimestamp();
        Console.WriteLine($"Start time: {(double)startTimestamp / Stopwatch.Frequency}");

        var sw = Stopwatch.StartNew();

        QuickSort(nums, 0, nums.Length - 1);

        sw.Stop();
        var endTimestamp = Stopwatch.GetTimestamp();

        PrintArray(nums);

        Console.WriteLine($"End time: {(double)endTimestamp / Stopwatch.Frequency}");
        Console.WriteLine($"Total time: {sw.Elapsed.TotalSeconds:F3}");

        Console.Out.Flush();
    }
}
