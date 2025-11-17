// Node.js program: quicksort random integers

function swap(arr, i, j) {
    const temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

function partition(arr, low, high) {
    const pivot = arr[high];
    let i = low - 1;
    for (let j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i + 1, high);
    return i + 1;
}

function quickSort(arr, low, high) {
    if (low < high) {
        const pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

function printArray(arr) {
    console.log(`First element: ${arr[0]}`);
    console.log(`Last element: ${arr[arr.length - 1]}`);
}

// ---- main ----
const n = 1_000_000;
const nums = new Array(n);
const min = 1;
const max = 100;

console.log("Sorting 1,000,000 random numbers from 1 to 100...");

// generate random numbers
for (let i = 0; i < n; i++) {
    nums[i] = Math.floor(Math.random() * (max - min + 1)) + min;
}

let start = process.hrtime.bigint();
console.log(`Start time: ${(Number(start) / 1e9).toFixed(3)}`);

printArray(nums);
quickSort(nums, 0, n - 1);

let end = process.hrtime.bigint();

printArray(nums);

console.log(`End time: ${(Number(end) / 1e9).toFixed(3)}`);
console.log(`Total time: ${(Number(end - start) / 1e9).toFixed(3)}`);
