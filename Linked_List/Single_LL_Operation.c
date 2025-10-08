#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function prototypes
void traverse(struct Node* head);
void insertAtBeginning(struct Node** head_ref, int new_data);
void insertAtEnd(struct Node** head_ref, int new_data);
void insertAfter(struct Node* prev_node, int new_data);
void deleteAtBeginning(struct Node** head_ref);
void deleteAtMiddle(struct Node** head_ref, int key);
void deleteAtEnd(struct Node** head_ref);

int main() {
    struct Node* head = NULL;

    // Insert nodes
    insertAtBeginning(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAfter(head->next, 4);

    printf("Circular Linked List after insertion: ");
    traverse(head);

    // Delete at beginning
    deleteAtBeginning(&head);
    printf("Circular Linked List after deleting at beginning: ");
    traverse(head);

    // Delete node with data 3
    deleteAtMiddle(&head, 3);
    printf("Circular Linked List after deleting node with data 3: ");
    traverse(head);

    // Delete at end
    deleteAtEnd(&head);
    printf("Circular Linked List after deleting at end: ");
    traverse(head);

    return 0;
}

// Function implementations as given above
