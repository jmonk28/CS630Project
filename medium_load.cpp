#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], size_t size) {
    std::cout << "First element: " << arr[0] << "\n";
    std::cout << "Last element: " << arr[size - 1] << "\n";
}

int main() {

    const long n = 1000000;
    int* nums = new int[n];
    int min = 1, max = 100;

    srand((unsigned)time(NULL));
    std::cout << "Sorting 10000 random numbers from 1 to 100...\n";

    for (long i = 0; i < n; i++) {
        nums[i] = min + rand() % (max - min + 1);
    }

    printArray(nums, n);

    auto start = std::chrono::high_resolution_clock::now();
    std::cout << "Start time: "
              << std::chrono::duration<double>(start.time_since_epoch()).count()
              << "\n";

    quickSort(nums, 0, n - 1);

    auto end = std::chrono::high_resolution_clock::now();

    printArray(nums, n);

    std::cout << "End time: "
              << std::chrono::duration<double>(end.time_since_epoch()).count()
              << "\n";

    double elapsed = std::chrono::duration<double>(end - start).count();
    std::cout << "Total time: " << elapsed << "\n";

    delete[] nums;
    return 0;
}
