use std::time::{SystemTime, UNIX_EPOCH};

fn main() {
    println!("Program starting...");

    let start = SystemTime::now();
    let start_secs = start.duration_since(UNIX_EPOCH).unwrap().as_secs_f64();
    println!("Start time: {:.6}", start_secs);

    let mut sum: i64 = 0;
    let n: i64 = 984_600_000;

    for i in 1..=n {
        sum += i;
    }

    let end = SystemTime::now();
    let end_secs = end.duration_since(UNIX_EPOCH).unwrap().as_secs_f64();
    println!("End time: {:.6}", end_secs);

    let elapsed = end.duration_since(start).unwrap().as_secs_f64();
    println!("Time elapsed: {:.8} seconds", elapsed);

    println!("Sum: {}", sum);
}
