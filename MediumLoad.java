import java.util.Random;

public class MediumLoad {

    // Swap two elements
    private static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    // Partition for QuickSort
    private static int partition(int[] arr, int low, int high) {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (arr[j] <= pivot) {
                i++;
                swap(arr, i, j);
            }
        }
        swap(arr, i + 1, high);
        return i + 1;
    }

    // Recursive QuickSort
    private static void quickSort(int[] arr, int low, int high) {
        if (low < high) {
            int pi = partition(arr, low, high);

            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }

    // Print first & last element only
    private static void printArray(int[] arr) {
        System.out.printf("First element: %d\n", arr[0]);
        System.out.printf("Last element: %d\n", arr[arr.length - 1]);
    }

    public static void main(String[] args) {

        int n = 1_000_000;
        int[] nums = new int[n];
        int min = 1, max = 100;

        Random rand = new Random(System.currentTimeMillis());

        System.out.println("Sorting 10000 random numbers from 1 to 100...");

        // Generate random values
        for (int i = 0; i < n; i++) {
            nums[i] = min + rand.nextInt(max - min + 1);
        }

        long start = System.nanoTime();
        System.out.printf("Start time: %.3f\n", start / 1_000_000_000.0);

        printArray(nums);
        quickSort(nums, 0, n - 1);

        long end = System.nanoTime();

        printArray(nums);

        System.out.printf("End time: %.3f\n", end / 1_000_000_000.0);
        System.out.printf("Total time: %.3f\n", (end - start) / 1_000_000_000.0);
    }
}
