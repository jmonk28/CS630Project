package main

import (
    "fmt"
    "time"
)

func multiply(a, b [][]int) [][]int {
    n := len(a)
    c := make([][]int, n)
    for i := range c {
        c[i] = make([]int, n)
    }

    for i := 0; i < n; i++ {
        for j := 0; j < n; j++ {
            sum := 0
            for k := 0; k < n; k++ {
                sum += a[i][k] * b[k][j]
            }
            c[i][j] = sum
        }
    }
    return c
}

func main() {
    const n = 2000

    // Initialize matrices
    a := make([][]int, n)
    b := make([][]int, n)
    for i := 0; i < n; i++ {
        a[i] = make([]int, n)
        b[i] = make([]int, n)
        for j := 0; j < n; j++ {
            a[i][j] = (i + j) % 10
            b[i][j] = (i * j) % 10
        }
    }

    fmt.Println("Program starting...")

    start := time.Now()
    fmt.Printf("Start time: %.6f\n", float64(start.UnixNano())/1e9)

    c := multiply(a, b)

    end := time.Now()
    fmt.Printf("End time: %.6f\n", float64(end.UnixNano())/1e9)

    elapsed := end.Sub(start).Seconds()
    fmt.Printf("Time elapsed: %.8f seconds\n", elapsed)

    fmt.Printf("c[0][0] = %d\n", c[0][0])
}
