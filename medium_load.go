package main

import (
    "fmt"
    "math/rand"
    "time"
)

func quicksort(arr []int) []int {
    if len(arr) < 2 {
        return arr
    }

    pivot := arr[len(arr)/2]
    left := []int{}
    right := []int{}

    for i, v := range arr {
        if i == len(arr)/2 {
            continue
        }
        if v < pivot {
            left = append(left, v)
        } else {
            right = append(right, v)
        }
    }

    left = quicksort(left)
    right = quicksort(right)

    return append(append(left, pivot), right...)
}

func main() {
    const size = 1000000
    rand.Seed(time.Now().UnixNano())

    arr := make([]int, size)
    for i := range arr {
        arr[i] = rand.Intn(100)
    }

    fmt.Println("Program starting...")

    start := time.Now()
    fmt.Printf("Start time: %.6f\n", float64(start.UnixNano())/1e9)

    sorted := quicksort(arr)

    end := time.Now()
    fmt.Printf("End time: %.6f\n", float64(end.UnixNano())/1e9)

	fmt.Printf("First element: %d\n", sorted[0])
	fmt.Printf("Last element: %d\n", sorted[len(sorted)-1])

    elapsed := end.Sub(start).Seconds()
    fmt.Printf("Time elapsed: %.8f seconds\n", elapsed)
}
