#include <stdio.h>

#define MAX 100

typedef struct {
    int coeff[MAX];
    int degree;
} Polynomial;


Polynomial addPolynomials(Polynomial p1, Polynomial p2) {
    Polynomial result;
    result.degree = (p1.degree > p2.degree) ? p1.degree : p2.degree;

    for (int i = 0; i <= result.degree; i++) {
        result.coeff[i] = 0;
        if (i <= p1.degree) result.coeff[i] += p1.coeff[i];
        if (i <= p2.degree) result.coeff[i] += p2.coeff[i];
    }

    return result;
}


Polynomial subtractPolynomials(Polynomial p1, Polynomial p2) {
    Polynomial result;
    result.degree = (p1.degree > p2.degree) ? p1.degree : p2.degree;

    for (int i = 0; i <= result.degree; i++) {
        result.coeff[i] = 0;
        if (i <= p1.degree) result.coeff[i] += p1.coeff[i];
        if (i <= p2.degree) result.coeff[i] -= p2.coeff[i];
    }

    return result;
}


Polynomial multiplyPolynomials(Polynomial p1, Polynomial p2) {
    Polynomial result;
    result.degree = p1.degree + p2.degree;

    for (int i = 0; i <= result.degree; i++) {
        result.coeff[i] = 0;
    }

    for (int i = 0; i <= p1.degree; i++) {
        for (int j = 0; j <= p2.degree; j++) {
            result.coeff[i + j] += p1.coeff[i] * p2.coeff[j];
        }
    }

    return result;
}

void dividePolynomials(Polynomial dividend, Polynomial divisor, Polynomial* quotient, Polynomial* remainder) {
    *quotient = (Polynomial){{0}, 0};
    *remainder = dividend;

    while (remainder->degree >= divisor.degree) {
        int deg_diff = remainder->degree - divisor.degree;
        int coeff_div = remainder->coeff[remainder->degree] / divisor.coeff[divisor.degree];

        Polynomial term = {{0}, deg_diff};
        term.coeff[deg_diff] = coeff_div;

        *quotient = addPolynomials(*quotient, term);
        Polynomial temp = multiplyPolynomials(term, divisor);
        *remainder = subtractPolynomials(*remainder, temp);
    }
}

void printPolynomial(Polynomial p) {
    for (int i = p.degree; i >= 0; i--) {
        printf("%dx^%d", p.coeff[i], i);
        if (i > 0) printf(" + ");
    }
    printf("\n");
}

int main() {
    Polynomial p1 = {{5, 0, 10, 6}, 3}; 
    Polynomial p2 = {{1, 2, 4}, 2};     

    // Addition
    Polynomial sum = addPolynomials(p1, p2);
    printf("Sum of polynomials: ");
    printPolynomial(sum);

    // Subtraction
    Polynomial diff = subtractPolynomials(p1, p2);
    printf("Difference of polynomials: ");
    printPolynomial(diff);

    // Multiplication
    Polynomial product = multiplyPolynomials(p1, p2);
    printf("Product of polynomials: ");
    printPolynomial(product);

    // Division
    Polynomial quotient, remainder;
    dividePolynomials(p1, p2, &quotient, &remainder);
    printf("Quotient of polynomials: ");
    printPolynomial(quotient);
    printf("Remainder of polynomials: ");
    printPolynomial(remainder);

    return 0;
}
