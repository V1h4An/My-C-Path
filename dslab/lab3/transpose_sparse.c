/* WAP to perform transpose of a given sparse matrix in 3-tuple format.*/
#include <stdio.h>

#define MAX 100

// Function to read a sparse matrix
void readSparseMatrix(int sparse[][3], int *size) {
    printf("Enter the number of non-zero elements: ");
    scanf("%d", size);

    printf("Enter the sparse matrix in 3-tuple format (row, column, value):\n");
    for (int i = 0; i < *size; i++) {
        scanf("%d %d %d", &sparse[i][0], &sparse[i][1], &sparse[i][2]);
    }
}

// Function to transpose a sparse matrix
void transposeSparseMatrix(int sparse[][3], int transposed[][3], int size) {
    for (int i = 0; i < size; i++) {
        transposed[i][0] = sparse[i][1];
        transposed[i][1] = sparse[i][0];
        transposed[i][2] = sparse[i][2];
    }
}

// Function to print a sparse matrix
void printSparseMatrix(int sparse[][3], int size) {
    printf("Row Column Value\n");
    for (int i = 0; i < size; i++) {
        printf("%d    %d    %d\n", sparse[i][0], sparse[i][1], sparse[i][2]);
    }
}

int main() {
    int sparse[MAX][3], transposed[MAX][3];
    int size;

    readSparseMatrix(sparse, &size);

    printf("Original Sparse Matrix:\n");
    printSparseMatrix(sparse, size);

    transposeSparseMatrix(sparse, transposed, size);

    printf("Transposed Sparse Matrix:\n");
    printSparseMatrix(transposed, size);

    return 0;
}
