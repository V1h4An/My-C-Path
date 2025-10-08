/*WAP to create a 1-D array of n elements and perform the following menu based operations 
using function.
a. insert a given element at specific position.
b. delete an element from a specific position of the array.
c. linear search to search an element
d. traversal of the array */
#include <stdio.h>
#include <stdlib.h>

void insertElement(int arr[], int *n, int pos, int elem) {
    if (pos < 0 || pos > *n) {
        printf("Invalid position!\n");
        return;
    }
    for (int i = *n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = elem;
    (*n)++;
}

void deleteElement(int arr[], int *n, int pos) {
    if (pos < 0 || pos >= *n) {
        printf("Invalid position!\n");
        return;
    }
    for (int i = pos; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
}

int linearSearch(int arr[], int n, int elem) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == elem) {
            return i;
        }
    }
    return -1;
}

void traverseArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n, choice, pos, elem;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[100]; // Assuming the maximum size of the array is 100
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert element\n");
        printf("2. Delete element\n");
        printf("3. Search element\n");
        printf("4. Traverse array\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the position to insert: ");
                scanf("%d", &pos);
                printf("Enter the element to insert: ");
                scanf("%d", &elem);
                insertElement(arr, &n, pos, elem);
                break;
            case 2:
                printf("Enter the position to delete: ");
                scanf("%d", &pos);
                deleteElement(arr, &n, pos);
                break;
            case 3:
                printf("Enter the element to search: ");
                scanf("%d", &elem);
                pos = linearSearch(arr, n, elem);
                if (pos != -1) {
                    printf("Element found at position %d\n", pos);
                } else {
                    printf("Element not found\n");
                }
                break;
            case 4:
                printf("Array elements: ");
                traverseArray(arr, n);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
