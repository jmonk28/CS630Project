import random
import time

def generate_matrix(size):
    min_val, max_val = 1, 10
    random.seed()

    matrix = []
    for i in range(size):
        row = [random.randint(min_val, max_val) for _ in range(size)]
        matrix.append(row)

    return matrix

def mat_multiply(matrix1, matrix2, size):
    # Initialize result matrix
    result = [[0] * size for _ in range(size)]

    for i in range(size):
        for j in range(size):
            s = 0
            for k in range(size):
                s += matrix1[i][k] * matrix2[k][j]
            result[i][j] = s

    return result

def main():
    size = 2000

    matrix1 = generate_matrix(size)
    matrix2 = generate_matrix(size)

    start = time.process_time()
    print("Start time: {:.3f}".format(start))

    result = mat_multiply(matrix1, matrix2, size)

    end = time.process_time()
    print("End time: {:.3f}".format(end))
    print("Total time: {:.3f}".format(end - start))

if __name__ == "__main__":
    main()
