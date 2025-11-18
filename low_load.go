package main

import (
    "fmt"
    "time"
)

func main() {
    fmt.Println("Program starting...")

    start := time.Now()
    fmt.Printf("Start time: %.6f\n", float64(start.UnixNano())/1e9)

    sum := 0
    for i := 0; i < 984_600_000; i++ {
        sum += i
    }

    end := time.Now()
    fmt.Printf("End time: %.6f\n", float64(end.UnixNano())/1e9)

    elapsed := end.Sub(start).Seconds()
    fmt.Printf("Time elapsed: %.8f seconds\n", elapsed)
    fmt.Printf("Sum: %d\n", sum)
}
