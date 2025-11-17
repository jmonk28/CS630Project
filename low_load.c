#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <stdint.h>

int main() {
    
    intmax_t sum = 0;
    intmax_t n = 984600000;
    clock_t start, end;

    printf("Program starting...\n");
    start = clock();
    printf("Start time: %.3f\n", (double)start / CLOCKS_PER_SEC);

    for (intmax_t i = 1; i <= n; i++) {
        sum += i;
    }

    end = clock();
    
    printf("End time: %.3f\n", (double)end / CLOCKS_PER_SEC);
    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time elapsed: %.8f seconds\n", cpu_time_used);
    printf("Sum: %lld", sum);

    return 0;
}