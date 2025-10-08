#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Define the structure of the queue
typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

// Function to create a new queue
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

// Function to add an item to the queue
void enqueue(Queue* queue, int item) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = item;
    newNode->next = NULL;

    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
        return;
    }

    queue->rear->next = newNode;
    queue->rear = queue->rear->next;
}

// Function to remove an item from the queue
int dequeue(Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue Underflow\n");
        return -1;
    }

    Node* temp = queue->front;
    int item = temp->data;
    queue->front = queue->front->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(temp);
    return item;
}

// Function to get the front item of the queue
int front(Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }
    return queue->front->data;
}

// Function to get the rear item of the queue
int rear(Queue* queue) {
    if (queue->rear == NULL) {
        printf("Queue is empty\n");
        return -1;
    }
    return queue->rear->data;
}

// Main function to demonstrate queue operations
int main() {
    Queue* queue = createQueue();

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);

    printf("Front item is %d\n", front(queue));
    printf("Rear item is %d\n", rear(queue));

    printf("Dequeued item is %d\n", dequeue(queue));
    printf("Dequeued item is %d\n", dequeue(queue));

    printf("Front item is %d\n", front(queue));
    printf("Rear item is %d\n", rear(queue));

    return 0;
}
