#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* create_node(int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to print the circular linked list
void print_list(struct Node* head) {
    if (head == NULL) return;
    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("%d (head)\n", head->data); // To indicate the circular nature
}

// Function to convert a singly linked list to a circular linked list
void convert_to_circular(struct Node* head) {
    if (head == NULL) return;
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head; // Link the last node to the first node
}

int main() {
    // Create a singly linked list
    struct Node* list = create_node(1);
    list->next = create_node(2);
    list->next->next = create_node(3);
    list->next->next->next = create_node(4);

    printf("Original list:\n");
    struct Node* temp = list;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    // Convert to circular linked list
    convert_to_circular(list);

    printf("Circular list:\n");
    print_list(list);

    return 0;
}
