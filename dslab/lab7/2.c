/*Write a menu driven program to implement linear queue operations such as Enqueue, 
Dequeue,  IsEmpty, Traverse using single linked list.*/

#include <stdio.h>
#include <stdlib.h>

// Define the structure for the node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Define the structure for the queue
typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

// Function to create a new node
Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (!new_node) {
        printf("Memory allocation error\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to initialize the queue
void initialize_queue(Queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

// Function to check if the queue is empty
int is_empty(Queue* q) {
    return q->front == NULL;
}

// Function to enqueue an element
void enqueue(Queue* q, int data) {
    Node* new_node = create_node(data);
    if (is_empty(q)) {
        q->front = q->rear = new_node;
    } else {
        q->rear->next = new_node;
        q->rear = new_node;
    }
    printf("Enqueued: %d\n", data);
}

// Function to dequeue an element
int dequeue(Queue* q) {
    if (is_empty(q)) {
        printf("Queue is empty!\n");
        return -1;
    } else {
        int data = q->front->data;
        Node* temp = q->front;
        q->front = q->front->next;
        free(temp);
        if (q->front == NULL) {
            q->rear = NULL;
        }
        printf("Dequeued: %d\n", data);
        return data;
    }
}

// Function to traverse the queue
void traverse(Queue* q) {
    if (is_empty(q)) {
        printf("Queue is empty!\n");
    } else {
        Node* temp = q->front;
        printf("Queue elements: ");
        while (temp) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Function to display the menu
void menu() {
    printf("\nQueue Operations Menu:\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Traverse\n");
    printf("4. Check if Queue is Empty\n");
    printf("5. Exit\n");
}

int main() {
    Queue q;
    initialize_queue(&q);
    int choice, element;

    while (1) {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d", &element);
                enqueue(&q, element);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                traverse(&q);
                break;
            case 4:
                if (is_empty(&q))
                    printf("Queue is empty.\n");
                else
                    printf("Queue is not empty.\n");
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }

    return 0;
}
