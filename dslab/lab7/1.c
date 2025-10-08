/*Write a menu driven program to create a linear queue using array and perform Enqueue,
Dequeue, Traverse, IsEmpty, IsFull operations.*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

typedef struct Queue {
    int front, rear;
    int items[SIZE];
} Queue;

void initialize(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int is_empty(Queue *q) {
    return q->front == -1;
}

int is_full(Queue *q) {
    return q->rear == SIZE - 1;
}

void enqueue(Queue *q, int value) {
    if (is_full(q)) {
        printf("Queue is full!\n");
    } else {
        if (q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
        printf("Enqueued: %d\n", value);
    }
}

int dequeue(Queue *q) {
    int item;
    if (is_empty(q)) {
        printf("Queue is empty!\n");
        return -1;
    } else {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            q->front = q->rear = -1;
        }
        printf("Dequeued: %d\n", item);
        return item;
    }
}

void traverse(Queue *q) {
    if (is_empty(q)) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue elements: ");
        for (int i = q->front; i <= q->rear; i++) {
            printf("%d ", q->items[i]);
        }
        printf("\n");
    }
}

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
    Queue q;
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
