/*Define a structure Node for a linked list with data (integer) and 
next (pointer to Node).
Write a function to insert a new node at the beginning of the list 

using a double pointer.*/
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};

void insertAtBeginning(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    new_node->data = new_data;


    new_node->next = (*head_ref);

    (*head_ref) = new_node;
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

void freeList(struct Node* head) {
   struct Node* tmp;
   while (head != NULL) {
       tmp = head;
       head = head->next;
       free(tmp);
    }
}

int main() {
    // Start with an empty list
    struct Node* head = NULL;

    printf("Initial list: ");
    printList(head);

    // Insert some elements at the beginning
    insertAtBeginning(&head, 30);
    printf("List after inserting 30: ");
    printList(head);

    insertAtBeginning(&head, 20);
    printf("List after inserting 20: ");
    printList(head);

    insertAtBeginning(&head, 10);
    printf("List after inserting 10: ");
    printList(head);

    // Free the allocated memory before exiting
    freeList(head);

    return 0;
}
