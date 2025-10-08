/*WAP to represent the polynomial of single variable using 1-D array and perform the addition 
of two polynomial equations.*/

#include <stdio.h>


void addPolynomials(int A[], int B[], int m, int n, int result[]) {
    int size = (m > n) ? m : n;

    for (int i = 0; i < size; i++) {
        result[i] = 0;
    }


    for (int i = 0; i < m; i++) {
        result[i] = A[i];
    }

    for (int i = 0; i < n; i++) {
        result[i] += B[i];
    }
}

void printPolynomial(int poly[], int size) {
    for (int i = 0; i < size; i++) {
        if (poly[i] != 0) {
            printf("%d", poly[i]);
            if (i != 0) {
                printf("x^%d", i);
            }
            if (i != size - 1) {
                printf(" + ");
            }
        }
    }
    printf("\n");
}

int main() {
    
    int A[] = {5, 0, 10, 6}; 
    int B[] = {1, 2, 4};     
    int m = sizeof(A) / sizeof(A[0]);
    int n = sizeof(B) / sizeof(B[0]);

    int size = (m > n) ? m : n;
    int result[size];

    addPolynomials(A, B, m, n, result);

    printf("First polynomial: ");
    printPolynomial(A, m);

    printf("Second polynomial: ");
    printPolynomial(B, n);

    printf("Sum of polynomials: ");
    printPolynomial(result, size);

    return 0;
}
