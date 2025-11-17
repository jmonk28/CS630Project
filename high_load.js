// Node.js program: matrix multiplication
function generateMatrix(size) {
    const min = 1, max = 10;
    const matrix = new Array(size);
    for (let i = 0; i < size; i++) {
        matrix[i] = new Array(size);
        for (let j = 0; j < size; j++) {
            matrix[i][j] = Math.floor(Math.random() * (max - min + 1)) + min;
        }
    }
    return matrix;
}

function matMultiply(A, B, size) {
    const C = new Array(size);
    for (let i = 0; i < size; i++) {
        C[i] = new Array(size);
        for (let j = 0; j < size; j++) {
            let sum = 0;
            for (let k = 0; k < size; k++) {
                sum += A[i][k] * B[k][j];
            }
            C[i][j] = sum;
        }
    }
    return C;
}

const matSize = 2000;

const matrix1 = generateMatrix(matSize);
const matrix2 = generateMatrix(matSize);

let start = process.hrtime.bigint();
console.log(`Start time: ${(Number(start) / 1e9).toFixed(3)}`);

const multiplied = matMultiply(matrix1, matrix2, matSize);

let end = process.hrtime.bigint();
console.log(`End time: ${(Number(end) / 1e9).toFixed(3)}`);
console.log(`Total time: ${(Number(end - start) / 1e9).toFixed(3)}`);
