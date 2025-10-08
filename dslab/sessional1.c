// Vihaan Mishra 2328139 CSSE 3
#include <stdio.h>

void mergeArrays(int A[], int B[], int sizeA, int sizeB) {
    int i = sizeA - 1;          
    int j = sizeB - sizeA - 1;  
    int k = sizeB - 1;

    while (i >= 0 && j >= 0) {
        if (A[i] > B[j]) {
            B[k--] = A[i--];
        } else {
            B[k--] = B[j--];
        }
    }

    while (i >= 0) {
        B[k--] = A[i--];
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int A[] = {2, 5, 8};
    int B[6] = {1, 3, 6};  
    int sizeA = sizeof(A) / sizeof(A[0]);
    int sizeB = sizeof(B) / sizeof(B[0]);

    mergeArrays(A, B, sizeA, sizeB);

    printf("Merged array: \n");
    printArray(B, sizeB);

    return 0;
char n;
printf("enter name");
scanf("%d",&n);
}
