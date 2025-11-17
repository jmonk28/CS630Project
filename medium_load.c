#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <stdint.h>

// Function to swap two elements
void swap(int *a, int *b) {
    long long temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function for Quick Sort
int partition(int* arr, int low, int high) {
    int pivot = arr[high]; // Choosing the last element as pivot
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// Quick Sort function (recursive)
void quickSort(int* arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        // Recursively sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to print the first and last elements of array (don't want to print whole array)
void printArray(int* arr, size_t size) {
    printf("First element: %lld\n", arr[0]);
    printf("Last element: %lld\n", arr[size - 1]);
}

int main() {

    long n = 1000000;
    int* nums = malloc(n * sizeof(int));
    size_t arr_size = 1000000;
    int min = 1, max = 100;
    clock_t start, end;

    // Seed the random number generator
    srand((unsigned int)time(NULL));
    printf("Sorting 10000 random numbers from 1 to 100...\n");

    // Generating numbers
    for (int i = 0; i < n; i++) {
        int randomNumber = min + rand() % (max-min + 1);
        nums[i] = randomNumber;
    }

    start = clock();
    printf("Start time: %.3f\n", (double)start / CLOCKS_PER_SEC);
    // Sorting numbers (quick sort)
    printArray(nums, arr_size);
    quickSort(nums, 0, arr_size-1);

    end = clock();

    // Print first and last elements after sort
    printArray(nums, arr_size);

    free(nums);
    fflush(stdout);
    printf("End time: %.3f\n", (double)end / CLOCKS_PER_SEC);
    printf("Total time: %.3f\n", (double)(end-start) / CLOCKS_PER_SEC);

    return 0;
}