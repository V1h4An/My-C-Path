/*Count the number of contiguous subarrays where sum is k
{1,3,5,2,5,1,2,3} let k =8 {2,5,1}is subarray
*/

#include <stdio.h>
#include <stdlib.h>

int countsubarray(int *arr, int size, int k) {
    int count = 0;
    for (int *p1 = arr; p1 < arr + size; p1++) {
        int sum = 0;
        for (int *p2 = p1; p2 < arr + size; p2++) { 
            sum += *p2;
            if (sum == k) { 
                count++;
            }
        }
    }
    return count;
}

int main() {
    int arr[] = {1, 3, 5, 2, 5, 1, 2, 3}; 
    int size = sizeof(arr) / sizeof(arr[0]);
    int k;

    printf("Enter the value of k: ");
    scanf("%d", &k);

    int result = countsubarray(arr, size, k); 
    printf("Number of contiguous subarrays with sum %d are %d\n", k, result);

    return 0;
}
