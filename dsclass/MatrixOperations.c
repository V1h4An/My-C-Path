#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Function to add two matrices
void addMatrices(int first[MAX][MAX], int second[MAX][MAX], int result[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = first[i][j] + second[i][j];
        }
    }
}

// Function to subtract two matrices
void subtractMatrices(int first[MAX][MAX], int second[MAX][MAX], int result[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = first[i][j] - second[i][j];
        }
    }
}

// Function to multiply two matrices
void multiplyMatrices(int first[MAX][MAX], int second[MAX][MAX], int result[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = 0;
            for (int k = 0; k < n; k++) {
                result[i][j] += first[i][k] * second[k][j];
            }
        }
    }
}

// Function to transpose a matrix
void transposeMatrix(int matrix[MAX][MAX], int result[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

// Function to find the determinant of a matrix
int determinant(int matrix[MAX][MAX], int n) {
    int det = 0;
    if (n == 1) {
        return matrix[0][0];
    } else if (n == 2) {
        return (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
    } else {
        int submatrix[MAX][MAX];
        for (int x = 0; x < n; x++) {
            int sub_i = 0;
            for (int i = 1; i < n; i++) {
                int sub_j = 0;
                for (int j = 0; j < n; j++) {
                    if (j == x) continue;
                    submatrix[sub_i][sub_j] = matrix[i][j];
                    sub_j++;
                }
                sub_i++;
            }
            det += (x % 2 == 0 ? 1 : -1) * matrix[0][x] * determinant(submatrix, n - 1);
        }
    }
    return det;
}

// Function to find the inverse of a matrix
void inverseMatrix(int matrix[MAX][MAX], float inverse[MAX][MAX], int n) {
    int det = determinant(matrix, n);
    if (det == 0) {
        printf("Inverse doesn't exist as determinant is zero.\n");
        return;
    }

    // Calculate the adjoint
    int adj[MAX][MAX];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int submatrix[MAX][MAX], sub_i = 0;
            for (int k = 0; k < n; k++) {
                if (k == i) continue;
                int sub_j = 0;
                for (int l = 0; l < n; l++) {
                    if (l == j) continue;
                    submatrix[sub_i][sub_j] = matrix[k][l];
                    sub_j++;
                }
                sub_i++;
            }
            adj[j][i] = (i + j) % 2 == 0 ? determinant(submatrix, n - 1) : -determinant(submatrix, n - 1);
        }
    }

    // Calculate the inverse
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            inverse[i][j] = (float) adj[i][j] / det;
        }
    }
}

// Function to print a matrix
void printMatrix(int matrix[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to print a float matrix
void printFloatMatrix(float matrix[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%.2f ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    int firstMatrix[MAX][MAX], secondMatrix[MAX][MAX], result[MAX][MAX];
    float inverse[MAX][MAX];

    // Input matrix size
    printf("Enter the size of the matrices (n x n): ");
    scanf("%d", &n);

    // Input first matrix
    printf("Enter elements of the first matrix (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &firstMatrix[i][j]);
        }
    }

    // Input second matrix
    printf("Enter elements of the second matrix (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &secondMatrix[i][j]);
        }
    }

    // Matrix addition
    addMatrices(firstMatrix, secondMatrix, result, n);
    printf("Sum of the matrices:\n");
    printMatrix(result, n);

    // Matrix subtraction
    subtractMatrices(firstMatrix, secondMatrix, result, n);
    printf("Difference of the matrices:\n");
    printMatrix(result, n);

    // Matrix multiplication
    multiplyMatrices(firstMatrix, secondMatrix, result, n);
    printf("Product of the matrices:\n");
    printMatrix(result, n);

    // Transpose of the first matrix
    transposeMatrix(firstMatrix, result, n);
    printf("Transpose of the first matrix:\n");
    printMatrix(result, n);

    // Determinant of the first matrix
    int det = determinant(firstMatrix, n);
    printf("Determinant of the first matrix: %d\n", det);

    // Inverse of the first matrix
    inverseMatrix(firstMatrix, inverse, n);
    printf("Inverse of the first matrix:\n");
    printFloatMatrix(inverse, n);

    return 0;
}
