#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

// Function prototypes
struct Node* createNode(int coeff, int exp);
void insertNode(struct Node** poly, int coeff, int exp);
void printPolynomial(struct Node* poly);
struct Node* addPolynomials(struct Node* poly1, struct Node* poly2);
struct Node* subtractPolynomials(struct Node* poly1, struct Node* poly2);
struct Node* multiplyPolynomials(struct Node* poly1, struct Node* poly2);
struct Node* dividePolynomials(struct Node* poly1, struct Node* poly2, struct Node** remainder);

// Main function
int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;
    struct Node* quotient = NULL;
    struct Node* remainder = NULL;

    // Create first polynomial: 5x^2 + 4x + 2
    insertNode(&poly1, 5, 2);
    insertNode(&poly1, 4, 1);
    insertNode(&poly1, 2, 0);

    // Create second polynomial: x + 1
    insertNode(&poly2, 1, 1);
    insertNode(&poly2, 1, 0);

    printf("Polynomial 1: ");
    printPolynomial(poly1);

    printf("Polynomial 2: ");
    printPolynomial(poly2);

    quotient = dividePolynomials(poly1, poly2, &remainder);

    printf("Quotient: ");
    printPolynomial(quotient);

    printf("Remainder: ");
    printPolynomial(remainder);

    return 0;
}

// Function to create a new node
struct Node* createNode(int coeff, int exp) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->coeff = coeff;
    new_node->exp = exp;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a new node into the polynomial linked list
void insertNode(struct Node** poly, int coeff, int exp) {
    struct Node* new_node = createNode(coeff, exp);
    if (*poly == NULL) {
        *poly = new_node;
    } else {
        struct Node* temp = *poly;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

// Function to print the polynomial linked list
void printPolynomial(struct Node* poly) {
    while (poly != NULL) {
        printf("%dx^%d", poly->coeff, poly->exp);
        poly = poly->next;
        if (poly != NULL) printf(" + ");
    }
    printf("\n");
}

// Function to add two polynomials
struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;
    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exp > poly2->exp) {
            insertNode(&result, poly1->coeff, poly1->exp);
            poly1 = poly1->next;
        } else if (poly1->exp < poly2->exp) {
            insertNode(&result, poly2->coeff, poly2->exp);
            poly2 = poly2->next;
        } else {
            insertNode(&result, poly1->coeff + poly2->coeff, poly1->exp);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }
    while (poly1 != NULL) {
        insertNode(&result, poly1->coeff, poly1->exp);
        poly1 = poly1->next;
    }
    while (poly2 != NULL) {
        insertNode(&result, poly2->coeff, poly2->exp);
        poly2 = poly2->next;
    }
    return result;
}

// Function to subtract two polynomials
struct Node* subtractPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;
    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exp > poly2->exp) {
            insertNode(&result, poly1->coeff, poly1->exp);
            poly1 = poly1->next;
        } else if (poly1->exp < poly2->exp) {
            insertNode(&result, -poly2->coeff, poly2->exp);
            poly2 = poly2->next;
        } else {
            insertNode(&result, poly1->coeff - poly2->coeff, poly1->exp);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }
    while (poly1 != NULL) {
        insertNode(&result, poly1->coeff, poly1->exp);
        poly1 = poly1->next;
    }
    while (poly2 != NULL) {
        insertNode(&result, -poly2->coeff, poly2->exp);
        poly2 = poly2->next;
    }
    return result;
}

// Function to multiply two polynomials
struct Node* multiplyPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;

    struct Node* poly1_temp = poly1;
    struct Node* poly2_temp = poly2;

    while (poly1_temp != NULL) {
        while (poly2_temp != NULL) {
            int coeff = poly1_temp->coeff * poly2_temp->coeff;
            int exp = poly1_temp->exp + poly2_temp->exp;
            insertNode(&result, coeff, exp);
            poly2_temp = poly2_temp->next;
        }
        poly2_temp = poly2;
        poly1_temp = poly1_temp->next;
    }

    return result;
}

// Function to divide two polynomials
struct Node* dividePolynomials(struct Node* poly1, struct Node* poly2, struct Node** remainder) {
    struct Node* quotient = NULL;
    *remainder = poly1;

    while (*remainder != NULL && (*remainder)->exp >= poly2->exp) {
        int coeff = (*remainder)->coeff / poly2->coeff;
        int exp = (*remainder)->exp - poly2->exp;
        insertNode(&quotient, coeff, exp);

        struct Node* term = createNode(coeff, exp);
        struct Node* temp = multiplyPolynomials(poly2, term);
        *remainder = subtractPolynomials(*remainder, temp);
    }

    return quotient;
}
