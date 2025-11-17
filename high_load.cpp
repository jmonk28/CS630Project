#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

int** generate_matrix(int size) {
    int min = 1, max = 10;
    int** matrix = new int*[size];

    for (int i = 0; i < size; i++) {
        matrix[i] = new int[size];
    }

    srand((unsigned)time(NULL));

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = min + rand() % (max - min + 1);
        }
    }

    return matrix;
}

int** mat_multiply(int** m1, int** m2, int size) {
    int** result = new int*[size];
    for (int i = 0; i < size; i++) {
        result[i] = new int[size];
    }

    int sum = 0;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            sum = 0;
            for (int k = 0; k < size; k++) {
                sum += m1[i][k] * m2[k][j];
            }
            result[i][j] = sum;
        }
    }

    return result;
}

int main() {

    int mat_size = 2000;

    int** matrix1 = generate_matrix(mat_size);
    int** matrix2 = generate_matrix(mat_size);

    auto start = std::chrono::high_resolution_clock::now();
    std::cout << "Start time: "
              << std::chrono::duration<double>(start.time_since_epoch()).count()
              << "\n";

    int** multiplied = mat_multiply(matrix1, matrix2, mat_size);

    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "End time: "
              << std::chrono::duration<double>(end.time_since_epoch()).count()
              << "\n";

    std::cout << "Total time: "
              << std::chrono::duration<double>(end - start).count()
              << "\n";

    for (int i = 0; i < mat_size; i++) {
        delete[] matrix1[i];
        delete[] matrix2[i];
        delete[] multiplied[i];
    }

    delete[] matrix1;
    delete[] matrix2;
    delete[] multiplied;

    return 0;
}
