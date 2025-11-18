use std::time::{SystemTime, UNIX_EPOCH};

fn quicksort(mut arr: Vec<i32>) -> Vec<i32> {
    if arr.len() < 2 {
        return arr;
    }

    let pivot = arr[arr.len() / 2];
    let mut left = Vec::new();
    let mut right = Vec::new();

    for (i, &value) in arr.iter().enumerate() {
        if i == arr.len() / 2 {
            continue;
        }
        if value < pivot {
            left.push(value);
        } else {
            right.push(value);
        }
    }

    let mut sorted = quicksort(left);
    sorted.push(pivot);
    sorted.extend(quicksort(right));
    sorted
}

fn main() {
    const SIZE: usize = 1_000_000;

    // Generate random values (fixed seed)
    let mut nums = Vec::with_capacity(SIZE);
    for i in 0..SIZE {
        nums.push(((i * 7919) % 1_000_000) as i32);
    }

    println!("Program starting...");

    let start = SystemTime::now();
    let start_secs = start.duration_since(UNIX_EPOCH).unwrap().as_secs_f64();
    println!("Start time: {:.6}", start_secs);

    let sorted = quicksort(nums);

    let end = SystemTime::now();
    let end_secs = end.duration_since(UNIX_EPOCH).unwrap().as_secs_f64();
    println!("End time: {:.6}", end_secs);

    let elapsed = end.duration_since(start).unwrap().as_secs_f64();
    println!("Time elapsed: {:.8} seconds", elapsed);

    println!("First element: {}", sorted[0]);
    println!("Last element: {}", sorted[sorted.len() - 1]);
}
