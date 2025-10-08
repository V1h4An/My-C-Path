/*Write a menu driven program to implement circular queue operations such as Enqueue,
Dequeue, Traverse, IsEmpty, IsFull using array.*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

typedef struct CircularQueue {
    int front, rear;
    int items[SIZE];
} CircularQueue;

// Function to initialize the circular queue
void initialize(CircularQueue *q) {
    q->front = q->rear = -1;
}

// Function to check if the circular queue is empty
int is_empty(CircularQueue *q) {
    return q->front == -1;
}

// Function to check if the circular queue is full
int is_full(CircularQueue *q) {
    return (q->rear + 1) % SIZE == q->front;
}

// Function to enqueue an element into the circular queue
void enqueue(CircularQueue *q, int value) {
    if (is_full(q)) {
        printf("Queue is full!\n");
    } else {
        if (is_empty(q)) {
            q->front = 0;
        }
        q->rear = (q->rear + 1) % SIZE;
        q->items[q->rear] = value;
        printf("Enqueued: %d\n", value);
    }
}

// Function to dequeue an element from the circular queue
int dequeue(CircularQueue *q) {
    int item;
    if (is_empty(q)) {
        printf("Queue is empty!\n");
        return -1;
    } else {
        item = q->items[q->front];
        if (q->front == q->rear) {
            q->front = q->rear = -1;
        } else {
            q->front = (q->front + 1) % SIZE;
        }
        printf("Dequeued: %d\n", item);
        return item;
    }
}

// Function to traverse the circular queue
void traverse(CircularQueue *q) {
    if (is_empty(q)) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue elements: ");
        int i = q->front;
        while (1) {
            printf("%d ", q->items[i]);
            if (i == q->rear) break;
            i = (i + 1) % SIZE;
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
    printf("5. Check if Queue is Full\n");
    printf("6. Exit\n");
}

int main() {
    CircularQueue q;
    initialize(&q);
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
                if (is_full(&q))
                    printf("Queue is full.\n");
                else
                    printf("Queue is not full.\n");
                break;
            case 6:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }

    return 0;
}
