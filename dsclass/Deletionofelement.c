/*Write a program that takes an array of integers and an integer value, 
then removes all occurrences of that value from the array. The program 
should shift the remaining elements to the left and reduce the size of 
the array accordingly, ensuring that no empty slots are 
left in the middle.*/

#include <stdio.h>

// Function to delete all occurrences of a value from the array
void deleteElement(int arr[], int *n, int value) {
    int i, j;
    for (i = 0; i < *n; i++) {
        if (arr[i] == value) {
            // Shift elements to the left to overwrite the deleted element
            for (j = i; j < *n - 1; j++) {
                arr[j] = arr[j + 1];
            }
            (*n)--; // Decrease the size of the array
            i--; // Check the current index again after shifting
        }
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 2, 2, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int value;
    
    printf("Array before deletion: ");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }

    printf("\nEnter value from array to be deleted\n");
    scanf("%d",&value);

    deleteElement(arr, &n, value);

    printf("Array after deletion: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
