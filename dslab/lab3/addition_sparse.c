/*WAP to perform addition of two given sparse matrix in 3–tuple format.*/

#include <stdio.h>

#define MAX 100

typedef struct {
    int row;
    int col;
    int value;
} Element;

void readSparseMatrix(Element sparse[], int *size) {
    printf("Enter the number of non-zero elements: ");
    scanf("%d", size);

    printf("Enter the sparse matrix in 3-tuple format (row, column, value):\n");
    for (int i = 0; i < *size; i++) {
        scanf("%d %d %d", &sparse[i].row, &sparse[i].col, &sparse[i].value);
    }
}

void addSparseMatrices(Element A[], int sizeA, Element B[], int sizeB, Element result[], int *sizeResult) {
    int i = 0, j = 0, k = 0;

    while (i < sizeA && j < sizeB) {
        if (A[i].row < B[j].row || (A[i].row == B[j].row && A[i].col < B[j].col)) {
            result[k++] = A[i++];
        } else if (B[j].row < A[i].row || (B[j].row == A[i].row && B[j].col < A[i].col)) {
            result[k++] = B[j++];
        } else {
            result[k] = A[i];
            result[k++].value = A[i++].value + B[j++].value;
        }
    }

    while (i < sizeA) {
        result[k++] = A[i++];
    }

    while (j < sizeB) {
        result[k++] = B[j++];
    }

    *sizeResult = k;
}

void printSparseMatrix(Element sparse[], int size) {
    printf("Row Column Value\n");
    for (int i = 0; i < size; i++) {
        printf("%d    %d    %d\n", sparse[i].row, sparse[i].col, sparse[i].value);
    }
}

int main() {
    Element A[MAX], B[MAX], result[MAX];
    int sizeA, sizeB, sizeResult;

    printf("Enter the first sparse matrix:\n");
    readSparseMatrix(A, &sizeA);

    printf("Enter the second sparse matrix:\n");
    readSparseMatrix(B, &sizeB);

    addSparseMatrices(A, sizeA, B, sizeB, result, &sizeResult);

    printf("First Sparse Matrix:\n");
    printSparseMatrix(A, sizeA);

    printf("Second Sparse Matrix:\n");
    printSparseMatrix(B, sizeB);

    printf("Sum of Sparse Matrices:\n");
    printSparseMatrix(result, sizeResult);

    return 0;
}
