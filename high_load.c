#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <stdint.h>

int** generate_matrix(int size) {
    // Matrix entries are from 1 to 100
    int min = 1, max = 10;
    int** matrix = malloc(size * sizeof(int*));

    for (int i = 0; i < size; i++) {
        matrix[i] = malloc(size * sizeof(int));  // allocate each row
    }

    srand((unsigned int)time(NULL));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = min + rand() % (max-min+1);
        }
    }

    return matrix;
}

int** mat_multiply(int** matrix1, int** matrix2, int size) {
    int** multiplied = malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        multiplied[i] = malloc(size * sizeof(int));  // allocate each row
    }
    int sum = 0;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            sum = 0;
            for (int k = 0; k < size; k++) {
                sum += matrix1[i][k] * matrix2[k][j];
            }
            multiplied[i][j] = sum;
        }
    }

    return multiplied;
}

void print_matrix(int** matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {

    int mat_size = 2000;
    int** matrix1 = malloc(mat_size * sizeof(int*));
    int** matrix2 = malloc(mat_size * sizeof(int*));
    clock_t start, end;

    matrix1 = generate_matrix(mat_size);
    matrix2 = generate_matrix(mat_size);
    
    start = clock();
    printf("Start time: %.3f\n", (double)start / CLOCKS_PER_SEC);
    int** multiplied = mat_multiply(matrix1, matrix2, mat_size);
    end = clock();

    // Freeing everything; don't need it after doing the calculation
    free(matrix1);
    free(matrix2);
    free(multiplied);
    printf("End time: %.3f\n", (double)end / CLOCKS_PER_SEC);
    printf("Total time: %.3f\n", (double)(end-start) / CLOCKS_PER_SEC);
    fflush(stdout);

    return 0;
}