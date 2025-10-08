#include <stdio.h>

#define M 4
#define N 5

// Function to preprocess the matrix
void preprocess(int mat[M][N], int aux[M][N]) {
    // Copy the first row of mat to aux
    for (int i = 0; i < N; i++)
        aux[0][i] = mat[0][i];

    // Column-wise sum
    for (int i = 1; i < M; i++)
        for (int j = 0; j < N; j++)
            aux[i][j] = mat[i][j] + aux[i-1][j];

    // Row-wise sum
    for (int i = 0; i < M; i++)
        for (int j = 1; j < N; j++)
            aux[i][j] += aux[i][j-1];
}

// Function to find the sum of submatrix
int sumQuery(int aux[M][N], int r1, int c1, int r2, int c2) {
    int res = aux[r2][c2];

    if (r1 > 0)
        res -= aux[r1-1][c2];

    if (c1 > 0)
        res -= aux[r2][c1-1];

    if (r1 > 0 && c1 > 0)
        res += aux[r1-1][c1-1];

    return res;
}

int main() {
    int mat[M][N] = {
        {1, 2, 3, 4, 6},
        {5, 3, 8, 1, 2},
        {4, 6, 7, 5, 5},
        {2, 4, 8, 9, 4}
    };

    int aux[M][N];
    preprocess(mat, aux);

    int r1 = 1, c1 = 1, r2 = 2, c2 = 2;
    printf("Sum of submatrix from (%d, %d) to (%d, %d) is %d\n", r1, c1, r2, c2, sumQuery(aux, r1, c1, r2, c2));

    return 0;
}
