/*Create a jagged array (array of arrays) where each row has a different
 number of columns. Write a program to calculate the sum of all elements 
 in the jagged array and print the result. Ensure that your solution can 
 handle varying row sizes and empty rows.*/


#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    // Allocate memory for the jagged array
    int **jaggedArray = (int **)malloc(rows * sizeof(int *));
    int *sizes = (int *)malloc(rows * sizeof(int));

    // Input the number of columns for each row and the elements
    for (int i = 0; i < rows; i++) {
        printf("Enter the number of columns for row %d: ", i + 1);
        scanf("%d", &sizes[i]);

        jaggedArray[i] = (int *)malloc(sizes[i] * sizeof(int));
        printf("Enter the elements for row %d: ", i + 1);
        for (int j = 0; j < sizes[i]; j++) {
            scanf("%d", &jaggedArray[i][j]);
        }
    }

    // Calculate the sum of all elements
    int sum = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < sizes[i]; j++) {
            sum += jaggedArray[i][j];
        }
    }

    // Print the result
    printf("The sum of all elements in the jagged array is: %d\n", sum);

    // Free allocated memory
    for (int i = 0; i < rows; i++) {
        free(jaggedArray[i]);
    }
    free(jaggedArray);
    free(sizes);

    return 0;
}
