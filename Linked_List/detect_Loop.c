#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


void Create_node(struct Node** head, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head);
    (*head) = new_node;
}


int detectLoop(struct Node* list) {
    struct Node *slow_p = list, *fast_p = list;
    while (slow_p != NULL && fast_p != NULL && fast_p->next !=NULL) {
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;
        if (slow_p == fast_p) {
            return 1; 
        }
    }
    return 0; 
}


int main() {
    struct Node* head = NULL;

   
    Create_node(&head, 20);
    Create_node(&head, 4);
    Create_node(&head, 15);
    Create_node(&head, 10);

    head->next->next->next->next = head;

    if (detectLoop(head))
        printf("Loop found\n");
    else
        printf("No Loop\n");

    return 0;
}
