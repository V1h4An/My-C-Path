/*Write a program to represent the given sparse matrix using header single 
linked list and display it*/

#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
struct Node {
    int row;
    int col;    
    int value;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int row, int col, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->row = row;
    newNode->col = col;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node into the linked list
void insertNode(struct Node** head, int row, int col, int value) {
    struct Node* newNode = createNode(row, col, value);
    newNode->next = *head;
    *head = newNode;
}

// Function to display the sparse matrix
void displaySparseMatrix(struct Node* head) {
    struct Node* temp = head;
    printf("Row\tColumn\tValue\n");
    while (temp != NULL) {
        printf("%d\t%d\t%d\n", temp->row, temp->col, temp->value);
        temp = temp->next;
    }
}

int main() {
    // Example sparse matrix
    int sparseMatrix[4][5] = {
        {0, 0, 3, 0, 4},
        {0, 0, 5, 7, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 6, 0, 0}
    };

    struct Node* head = NULL;

    // Convert sparse matrix to linked list
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            if (sparseMatrix[i][j] != 0) {
                insertNode(&head, i, j, sparseMatrix[i][j]);
            }
        }
    }

    // Display the sparse matrix
    displaySparseMatrix(head);

    return 0;
}
