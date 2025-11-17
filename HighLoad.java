import java.util.Random;

public class HighLoad {

    // Generate an NxN matrix filled with random ints from 1 to 10
    public static int[][] generateMatrix(int size) {
        int min = 1, max = 10;
        int[][] matrix = new int[size][size];
        Random rand = new Random(System.currentTimeMillis());

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                matrix[i][j] = min + rand.nextInt(max - min + 1);
            }
        }
        return matrix;
    }

    // Matrix multiplication
    public static int[][] matMultiply(int[][] A, int[][] B, int size) {
        int[][] C = new int[size][size];

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                int sum = 0;
                for (int k = 0; k < size; k++) {
                    sum += A[i][k] * B[k][j];
                }
                C[i][j] = sum;
            }
        }

        return C;
    }

    public static void main(String[] args) {

        int matSize = 2000;

        int[][] matrix1 = generateMatrix(matSize);
        int[][] matrix2 = generateMatrix(matSize);

        long start = System.nanoTime();
        System.out.printf("Start time: %.3f\n", start / 1_000_000_000.0);

        int[][] multiplied = matMultiply(matrix1, matrix2, matSize);

        long end = System.nanoTime();

        System.out.printf("End time: %.3f\n", end / 1_000_000_000.0);
        System.out.printf("Total time: %.3f\n", (end - start) / 1_000_000_000.0);
    }
}
