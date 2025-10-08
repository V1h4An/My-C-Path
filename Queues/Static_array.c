#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Define the structure of the queue
typedef struct Queue {
    int items[MAX_SIZE];
    int front;
    int rear;
} Queue;

// Function to create a new queue
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

// Function to check if the queue is full
int isFull(Queue* queue) {
    return queue->rear == MAX_SIZE - 1;
}

// Function to check if the queue is empty
int isEmpty(Queue* queue) {
    return queue->front == -1 || queue->front > queue->rear;
}

// Function to add an item to the queue
void enqueue(Queue* queue, int item) {
    if (isFull(queue)) {
        printf("Queue Overflow\n");
        return;
    }
    if (queue->front == -1) {
        queue->front = 0;
    }
    queue->items[++queue->rear] = item;
}

// Function to remove an item from the queue
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue Underflow\n");
        return -1;
    }
    return queue->items[queue->front++];
}

// Function to get the front item of the queue
int front(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    return queue->items[queue->front];
}

// Function to get the rear item of the queue
int rear(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    return queue->items[queue->rear];
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
