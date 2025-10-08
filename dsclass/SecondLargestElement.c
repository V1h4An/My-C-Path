/*Write a program that takes an array of integers and finds the
second largest element in the array. Ensure your solution works 
efficiently for both small and large arrays, and handles cases 
where there are duplicate elements or the array size is less than two.*/
#include <stdio.h>
#include <limits.h>

// Function to find the second largest element in an array
void findSecondLargest(int arr[], int n) {
    if (n < 2) {
        printf("Array size is less than two.\n");
        return;
    }

    int first = INT_MIN, second = INT_MIN;

    // Traverse the array to find the largest and second largest elements
    for (int i = 0; i < n; i++) {
        if (arr[i] > first) {
            second = first; // Update second largest
            first = arr[i]; // Update largest
        } else if (arr[i] > second && arr[i] != first) {
            second = arr[i]; // Update second largest
        }
    }

    if (second == INT_MIN) {
        printf("There is no second largest element.\n");
    } else {
        printf("The second largest element is %d\n", second);
    }
}

int main() {
    int arr[] = {12, 35, 1, 10, 34, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    findSecondLargest(arr, n);
    return 0;
} 