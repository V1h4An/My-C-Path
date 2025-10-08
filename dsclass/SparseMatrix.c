#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int row;
    int col;
    int value;
} Element;

typedef struct {
    int rows;
    int cols;
    int num;
    Element elements[MAX];
} SparseMatrix;

// Function to add two sparse matrices
SparseMatrix addSparseMatrices(SparseMatrix sm1, SparseMatrix sm2) {
    SparseMatrix result;
    result.rows = sm1.rows;
    result.cols = sm1.cols;
    result.num = 0;

    int i = 0, j = 0;
    while (i < sm1.num && j < sm2.num) {
        if (sm1.elements[i].row < sm2.elements[j].row ||
           (sm1.elements[i].row == sm2.elements[j].row && sm1.elements[i].col < sm2.elements[j].col)) {
            result.elements[result.num++] = sm1.elements[i++];
        } else if (sm1.elements[i].row > sm2.elements[j].row ||
                  (sm1.elements[i].row == sm2.elements[j].row && sm1.elements[i].col > sm2.elements[j].col)) {
            result.elements[result.num++] = sm2.elements[j++];
        } else {
            result.elements[result.num] = sm1.elements[i];
            result.elements[result.num++].value = sm1.elements[i++].value + sm2.elements[j++].value;
        }
    }

    while (i < sm1.num) {
        result.elements[result.num++] = sm1.elements[i++];
    }

    while (j < sm2.num) {
        result.elements[result.num++] = sm2.elements[j++];
    }

    return result;
}

// Function to subtract two sparse matrices
SparseMatrix subtractSparseMatrices(SparseMatrix sm1, SparseMatrix sm2) {
    SparseMatrix result;
    result.rows = sm1.rows;
    result.cols = sm1.cols;
    result.num = 0;

    int i = 0, j = 0;
    while (i < sm1.num && j < sm2.num) {
        if (sm1.elements[i].row < sm2.elements[j].row ||
           (sm1.elements[i].row == sm2.elements[j].row && sm1.elements[i].col < sm2.elements[j].col)) {
            result.elements[result.num++] = sm1.elements[i++];
        } else if (sm1.elements[i].row > sm2.elements[j].row ||
                  (sm1.elements[i].row == sm2.elements[j].row && sm1.elements[i].col > sm2.elements[j].col)) {
            result.elements[result.num] = sm2.elements[j++];
            result.elements[result.num++].value = -result.elements[result.num - 1].value;
        } else {
            result.elements[result.num] = sm1.elements[i];
            result.elements[result.num++].value = sm1.elements[i++].value - sm2.elements[j++].value;
        }
    }

    while (i < sm1.num) {
        result.elements[result.num++] = sm1.elements[i++];
    }

    while (j < sm2.num) {
        result.elements[result.num] = sm2.elements[j++];
        result.elements[result.num++].value = -result.elements[result.num - 1].value;
    }

    return result;
}

// Function to transpose a sparse matrix
SparseMatrix transposeSparseMatrix(SparseMatrix sm) {
    SparseMatrix result;
    result.rows = sm.cols;
    result.cols = sm.rows;
    result.num = sm.num;

    int index = 0;
    for (int col = 0; col < sm.cols; col++) {
        for (int i = 0; i < sm.num; i++) {
            if (sm.elements[i].col == col) {
                result.elements[index].row = sm.elements[i].col;
                result.elements[index].col = sm.elements[i].row;
                result.elements[index].value = sm.elements[i].value;
                index++;
            }
        }
    }

    return result;
}

// Function to multiply two sparse matrices
SparseMatrix multiplySparseMatrices(SparseMatrix sm1, SparseMatrix sm2) {
    SparseMatrix result;
    result.rows = sm1.rows;
    result.cols = sm2.cols;
    result.num = 0;

    if (sm1.cols != sm2.rows) {
        printf("Matrix multiplication not possible.\n");
        return result;
    }

    SparseMatrix sm2T = transposeSparseMatrix(sm2);
    int temp[MAX][MAX] = {0};

    for (int i = 0; i < sm1.num; i++) {
        for (int j = 0; j < sm2T.num; j++) {
            if (sm1.elements[i].col == sm2T.elements[j].col) {
                temp[sm1.elements[i].row][sm2T.elements[j].row] += sm1.elements[i].value * sm2T.elements[j].value;
            }
        }
    }

    for (int i = 0; i < sm1.rows; i++) {
        for (int j = 0; j < sm2.cols; j++) {
            if (temp[i][j] != 0) {
                result.elements[result.num].row = i;
                result.elements[result.num].col = j;
                result.elements[result.num++].value = temp[i][j];
            }
        }
    }

    return result;
}

// Function to print a sparse matrix
void printSparseMatrix(SparseMatrix sm) {
    printf("Row\tColumn\tValue\n");
    for (int i = 0; i < sm.num; i++) {
        printf("%d\t%d\t%d\n", sm.elements[i].row, sm.elements[i].col, sm.elements[i].value);
    }
}

int main() {
    SparseMatrix sm1 = {3, 3, 4, {{0, 0, 3}, {0, 2, 5}, {1, 1, 7}, {2, 2, 9}}};
    SparseMatrix sm2 = {3, 3, 3, {{0, 1, 6}, {1, 1, 3}, {2, 2, 8}}};

    // Addition
    SparseMatrix sum = addSparseMatrices(sm1, sm2);
    printf("Sum of sparse matrices:\n");
    printSparseMatrix(sum);

    // Subtraction
    SparseMatrix diff = subtractSparseMatrices(sm1, sm2);
    printf("Difference of sparse matrices:\n");
    printSparseMatrix(diff);

    // Transpose
    SparseMatrix trans = transposeSparseMatrix(sm1);
    printf("Transpose of the first sparse matrix:\n");
    printSparseMatrix(trans);

    // Multiplication
    SparseMatrix product = multiplySparseMatrices(sm1, sm2);
    printf("Product of sparse matrices:\n");
    printSparseMatrix(product);

    return 0;
}
