#include <stdio.h>

// Function to find a peak element in the array
int findPeakElement(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        // Check if the current element is a peak element
        if ((i == 0 || arr[i] >= arr[i - 1]) && (i == n - 1 || arr[i] >= arr[i + 1])) {
            return i;
        }
    }
    return -1; // This should never be reached if array has at least one element
}

int main() {
    int arr[] = {1, 3, 20, 4, 1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    int peakIndex = findPeakElement(arr, n);
    if (peakIndex != -1) {
        printf("Peak element is at index %d with value %d\n", peakIndex, arr[peakIndex]);
    } else {
        printf("No peak element found.\n");
    }
    return 0;
}
