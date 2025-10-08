#include <stdio.h>
#include <stdlib.h>
#include <limits.h> 

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

void findSecondLargest(struct Node* head) {
    if (head == NULL || head->next == NULL) {
        printf("The list has fewer than two elements. No second largest element exists.\n");
        return;
    }

    int largest = INT_MIN;
    int secondLargest = INT_MIN;

    struct Node* current = head;

    while (current != NULL) {
        if (current->data > largest) {
            secondLargest = largest;
            largest = current->data;
        }
        else if (current->data > secondLargest && current->data < largest) {
            secondLargest = current->data;
        }
        current = current->next;
    }

    if (secondLargest == INT_MIN) {
        printf("There is no distinct second largest element.\n");
    } else {
        printf("The second largest element is: %d\n", secondLargest);
    }
}

int main() {
    // Start with an empty list
    struct Node* head = NULL;

    printf("Initial list: ");
    printList(head);

    insertAtBeginning(&head, 30);
    printf("List after inserting 30: ");
    printList(head);

    insertAtBeginning(&head, 20);
    printf("List after inserting 20: ");
    printList(head);

    insertAtBeginning(&head, 10);
    printf("List after inserting 10: ");
    printList(head);

    findSecondLargest(head);

    freeList(head);

    return 0;
}

