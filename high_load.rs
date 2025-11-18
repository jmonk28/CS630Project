use std::time::{SystemTime, UNIX_EPOCH};

fn mat_multiply(a: &Vec<Vec<i32>>, b: &Vec<Vec<i32>>, size: usize) -> Vec<Vec<i32>> {
    let mut result = vec![vec![0; size]; size];

    for i in 0..size {
        for j in 0..size {
            let mut sum = 0;
            for k in 0..size {
                sum += a[i][k] * b[k][j];
            }
            result[i][j] = sum;
        }
    }
    result
}

fn main() {
    const N: usize = 2000;

    // Initialize matrices
    let mut a = vec![vec![0; N]; N];
    let mut b = vec![vec![0; N]; N];

    for i in 0..N {
        for j in 0..N {
            a[i][j] = ((i + j) % 10) as i32;
            b[i][j] = ((i * j) % 10) as i32;
        }
    }

    println!("Program starting...");

    let start = SystemTime::now();
    let start_secs = start.duration_since(UNIX_EPOCH).unwrap().as_secs_f64();
    println!("Start time: {:.6}", start_secs);

    let c = mat_multiply(&a, &b, N);

    let end = SystemTime::now();
    let end_secs = end.duration_since(UNIX_EPOCH).unwrap().as_secs_f64();
    println!("End time: {:.6}", end_secs);

    let elapsed = end.duration_since(start).unwrap().as_secs_f64();
    println!("Time elapsed: {:.8} seconds", elapsed);

    println!("c[0][0] = {}", c[0][0]);
}
