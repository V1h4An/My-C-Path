/*You are given an array of integer where every element except 1 repeats twice
find the element that appears only once*/

#include <stdio.h>

int findSingle(int arr[], int n) {
    int result = 0;
    for (int i = 0; i < n; i++) {
        result ^= arr[i];
    }
    return result;
}

int main() {
    int arr[] = {2, 1, 2, 1, 3, 5, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("The element that appears only once is %d\n", findSingle(arr, n));
    return 0;
}
