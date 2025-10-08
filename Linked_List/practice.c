#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to find the intersection point of two linked lists
struct Node* getIntersectionNode(struct Node* head1, struct Node* head2) {
    struct Node* ptr1 = head1;
    struct Node* ptr2 = head2;

    // If either head is NULL, there is no intersection
    if (head1 == NULL || head2 == NULL) {
        return NULL;
    }

    // Traverse both lists
    while (ptr1 != ptr2) {
        ptr1 = (ptr1 == NULL) ? head2 : ptr1->next;
        ptr2 = (ptr2 == NULL) ? head1 : ptr2->next;
    }

    return ptr1;
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    // Create two linked lists
    struct Node* head1 = createNode(1);
    head1->next = createNode(2);
    head1->next->next = createNode(3);
    head1->next->next->next = createNode(4);
    head1->next->next->next->next = createNode(5);

    struct Node* head2 = createNode(10);
    head2->next = createNode(20);
    head2->next->next = head1->next->next; // Intersection at node with data 3

    printf("List 1: ");
    printList(head1);

    printf("List 2: ");
    printList(head2);

    struct Node* intersection = getIntersectionNode(head1, head2);
    if (intersection != NULL) {
        printf("Intersection at node with data: %d\n", intersection->data);
    } else {
        printf("No intersection found.\n");
    }

    return 0;
}

