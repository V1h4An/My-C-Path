/*Write a program to perform the following operations on a given square matrix using functions: 
i.   Find the no.of nonzero elements
ii.  Display upper triangular matrix
iii. Display the elements of just above and below the main diagonal*/

#include <stdio.h>

#define MAX 100

// Function to find the number of nonzero elements
int countNonZeroElements(int matrix[MAX][MAX], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] != 0) {
                count++;
            }
        }
    }
    return count;
}

// Function to display the upper triangular matrix
void displayUpperTriangular(int matrix[MAX][MAX], int n) {
    printf("Upper Triangular Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i <= j) {
                printf("%d ", matrix[i][j]);
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

// Function to display elements just above and below the main diagonal
void displayDiagonalElements(int matrix[MAX][MAX], int n) {
    printf("Elements just above and below the main diagonal:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j - 1 || i == j + 1) {
                printf("%d ", matrix[i][j]);
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

int main() {
    int n;
    int matrix[MAX][MAX];
    int choice;

    printf("Enter the size of the square matrix: ");
    scanf("%d", &n);

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    while (1) {
        printf("\nMenu:\n");
        printf("1. Find the number of nonzero elements\n");
        printf("2. Display upper triangular matrix\n");
        printf("3. Display elements just above and below the main diagonal\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Number of nonzero elements: %d\n", countNonZeroElements(matrix, n));
                break;
            case 2:
                displayUpperTriangular(matrix, n);
                break;
            case 3:
                displayDiagonalElements(matrix, n);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
