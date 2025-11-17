using System;
using System.Diagnostics;

class HighLoad
{
    static int[][] GenerateMatrix(int size)
    {
        int min = 1, max = 10;
        int[][] matrix = new int[size][];

        Random rand = new Random();

        for (int i = 0; i < size; i++)
        {
            matrix[i] = new int[size];
            for (int j = 0; j < size; j++)
                matrix[i][j] = rand.Next(min, max + 1);
        }

        return matrix;
    }

    static int[][] Multiply(int[][] m1, int[][] m2, int size)
    {
        int[][] result = new int[size][];
        for (int i = 0; i < size; i++)
            result[i] = new int[size];

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                int sum = 0;
                for (int k = 0; k < size; k++)
                    sum += m1[i][k] * m2[k][j];

                result[i][j] = sum;
            }
        }

        return result;
    }

    static void Main(string[] args)
    {
        int size = 2000;

        int[][] matrix1 = GenerateMatrix(size);
        int[][] matrix2 = GenerateMatrix(size);

        var startTimestamp = Stopwatch.GetTimestamp();
        Console.WriteLine($"Start time: {(double)startTimestamp / Stopwatch.Frequency}");

        var sw = Stopwatch.StartNew();

        int[][] multiplied = Multiply(matrix1, matrix2, size);

        sw.Stop();
        var endTimestamp = Stopwatch.GetTimestamp();

        Console.WriteLine($"End time: {(double)endTimestamp / Stopwatch.Frequency}");
        Console.WriteLine($"Total time: {sw.Elapsed.TotalSeconds:F3}");

        Console.Out.Flush();
    }
}
