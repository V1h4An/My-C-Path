#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;      // Pointer to the array elements
    int size;       // Current number of elements
    int capacity;   // Maximum capacity of the array
} ArrayADT;

// Function to create an array with a given capacity
ArrayADT* createArray(int capacity) {
    ArrayADT *arr = (ArrayADT *)malloc(sizeof(ArrayADT));
    arr->data = (int *)malloc(capacity * sizeof(int));
    arr->size = 0;
    arr->capacity = capacity;
    return arr;
}

// Function to increase the capacity of the array
void increaseCapacity(ArrayADT *arr) {
    int newCapacity = arr->capacity * 2;
    int *newData = (int *)malloc(newCapacity * sizeof(int));
    for (int i = 0; i < arr->size; i++) {
        newData[i] = arr->data[i];
    }
    free(arr->data);
    arr->data = newData;
    arr->capacity = newCapacity;
    printf("Array capacity increased to %d\n", newCapacity);
}

// Function to insert an element at the end of the array
void insertAtEnd(ArrayADT *arr, int element) {
    if (arr->size == arr->capacity) {
        increaseCapacity(arr);
    }
    arr->data[arr->size] = element;
    arr->size++;
}

// Function to insert an element at a specified position in the array
void insertAtPosition(ArrayADT *arr, int element, int position) {
    if (position < 0 || position > arr->size) {
        printf("Invalid position\n");
        return;
    }
    if (arr->size == arr->capacity) {
        increaseCapacity(arr);
    }
    for (int i = arr->size; i > position; i--) {
        arr->data[i] = arr->data[i - 1];
    }
    arr->data[position] = element;
    arr->size++;
}

// Function to delete an element from the end of the array
void deleteFromEnd(ArrayADT *arr) {
    if (arr->size == 0) {
        printf("Array is empty\n");
        return;
    }
    arr->size--;
}

// Function to delete an element from a specified position in the array
void deleteFromPosition(ArrayADT *arr, int position) {
    if (position < 0 || position >= arr->size) {
        printf("Invalid position\n");
        return;
    }
    for (int i = position; i < arr->size - 1; i++) {
        arr->data[i] = arr->data[i + 1];
    }
    arr->size--;
}

// Function to search for an element in the array
int search(ArrayADT *arr, int element) {
    for (int i = 0; i < arr->size; i++) {
        if (arr->data[i] == element) {
            return i;
        }
    }
    return -1;
}

// Function to retrieve a single value from the array
int retrieveValue(ArrayADT *arr, int index) {
    if (index < 0 || index >= arr->size) {
        printf("Invalid index\n");
        return -1;
    }
    return arr->data[index];
}

// Function to retrieve a sub-array from the array
ArrayADT* retrieveSubArray(ArrayADT *arr, int from, int to) {
    if (from < 0 || to > arr->size || from >= to) {
        printf("Invalid indices\n");
        return NULL;
    }
    ArrayADT *subArray = createArray(to - from);
    for (int i = from; i < to; i++) {
        insertAtEnd(subArray, arr->data[i]);
    }
    return subArray;
}

// Function to free the memory allocated for the array
void freeArray(ArrayADT *arr) {
    free(arr->data);
    free(arr);
}

int main() {
    ArrayADT *arr = createArray(3); // Start with a small capacity

    // Insert more elements to exceed the initial capacity
    insertAtEnd(arr, 1);
    insertAtEnd(arr, 2);
    insertAtEnd(arr, 3);
    insertAtEnd(arr, 4); // This should trigger an increase in capacity
    insertAtEnd(arr, 5); // Add more elements to ensure capacity increase

    printf("Array after insertion: ");
    for (int i = 0; i < arr->size; i++) {
        printf("%d ", arr->data[i]);
    }
    printf("\n");

    // Demonstrating other operations
    insertAtPosition(arr, 20, 2);
    printf("Array after inserting 20 at position 2: ");
    for (int i = 0; i < arr->size; i++) {
        printf("%d ", arr->data[i]);
    }
    printf("\n");

    deleteFromEnd(arr);
    printf("Array after deleting from end: ");
    for (int i = 0; i < arr->size; i++) {
        printf("%d ", arr->data[i]);
    }
    printf("\n");

    deleteFromPosition(arr, 1);
    printf("Array after deleting from position 1: ");
    for (int i = 0; i < arr->size; i++) {
        printf("%d ", arr->data[i]);
    }
    printf("\n");

    int index = search(arr, 15);
    if (index != -1) {
        printf("Element 15 found at index %d\n", index);
    } else {
        printf("Element 15 not found\n");
    }

    int value = retrieveValue(arr, 1);
    if (value != -1) {
        printf("Element at index 1 is %d\n", value);
    }

    ArrayADT *subArray = retrieveSubArray(arr, 0, 3);
    printf("Sub-array from index 0 to 3: ");
    for (int i = 0; i < subArray->size; i++) {
        printf("%d ", subArray->data[i]);
    }
    printf("\n");

    freeArray(subArray);
    freeArray(arr);

    return 0;
}
