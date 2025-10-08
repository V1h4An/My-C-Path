/*WAP to represent a given sparse matrix in 3-tuple format using 2-D array. */

#include <stdio.h>

#define MAX 100

void createSparseMatrix(int matrix[MAX][MAX], int sparse[MAX][3], int rows, int cols) {
    int k = 1; // Start from 1 because 0th row is used for indexing
    sparse[0][0] = rows;
    sparse[0][1] = cols;
    sparse[0][2] = 0; // Initialize count of non-zero elements

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = matrix[i][j];
                k++;
                sparse[0][2]++;
            }
        }
    }
}

void printSparseMatrix(int sparse[MAX][3]) {
    int nonZeroElements = sparse[0][2];
    printf("Sparse Matrix in 3-tuple format:\n");
    printf("Row\tColumn\tValue\n");
    for (int i = 0; i <= nonZeroElements; i++) {
        printf("%d\t%d\t%d\n", sparse[i][0], sparse[i][1], sparse[i][2]);
    }
}

int main() {
    int rows, cols;
    int matrix[MAX][MAX];
    int sparse[MAX][3];

    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    createSparseMatrix(matrix, sparse, rows, cols);
    printSparseMatrix(sparse);

    return 0;
}
