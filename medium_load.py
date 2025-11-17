import random
import time
import sys

# Increase recursion limit so recursive QuickSort won't crash
sys.setrecursionlimit(2_000_000)

def swap(arr, a, b):
    arr[a], arr[b] = arr[b], arr[a]

def partition(arr, low, high):
    pivot = arr[high]
    i = low - 1

    for j in range(low, high):
        if arr[j] <= pivot:
            i += 1
            swap(arr, i, j)

    swap(arr, i + 1, high)
    return i + 1

def quicksort(arr, low, high):
    if low < high:
        p = partition(arr, low, high)
        quicksort(arr, low, p - 1)
        quicksort(arr, p + 1, high)

def main():

    n = 1_000_000
    arr = [0] * n
    min_val, max_val = 1, 100

    random.seed()

    print("Sorting 10000 random numbers from 1 to 100...")

    # Generate 1M random numbers
    for i in range(n):
        arr[i] = random.randint(min_val, max_val)

    print("First element: {}".format(arr[0]))
    print("Last element: {}".format(arr[-1]))

    start = time.process_time()
    print("Start time: {:.3f}".format(start))

    quicksort(arr, 0, n - 1)

    end = time.process_time()

    print("First element: {}".format(arr[0]))
    print("Last element: {}".format(arr[-1]))

    print("End time: {:.3f}".format(end))
    print("Total time: {:.3f}".format(end - start))


if __name__ == "__main__":
    main()
