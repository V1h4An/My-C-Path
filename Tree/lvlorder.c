#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Define the structure of a tree node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Define the structure of the queue
typedef struct Queue {
    Node* items[MAX_SIZE];
    int front;
    int rear;
} Queue;

// Function to create a new tree node
Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to create a new queue
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

// Function to check if the queue is empty
int isEmpty(Queue* queue) {
    return queue->front == -1 || queue->front > queue->rear;
}

// Function to check if the queue is full
int isFull(Queue* queue) {
    return queue->rear == MAX_SIZE - 1;
}

// Function to enqueue a tree node
void enqueue(Queue* queue, Node* item) {
    if (isFull(queue)) {
        printf("Queue Overflow\n");
        return;
    }
    if (queue->front == -1) {
        queue->front = 0;
    }
    queue->items[++queue->rear] = item;
}

// Function to dequeue a tree node
Node* dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue Underflow\n");
        return NULL;
    }
    return queue->items[queue->front++];
}

// Function to perform level order traversal
void levelOrder(Node* root) {
    if (root == NULL) {
        return;
    }

    Queue* queue = createQueue();
    enqueue(queue, root);

    while (!isEmpty(queue)) {
        Node* node = dequeue(queue);
        printf("%d ", node->data);

        if (node->left != NULL) {
            enqueue(queue, node->left);
        }
        if (node->right != NULL) {
            enqueue(queue, node->right);
        }
    }

    free(queue);
}

// Main function to demonstrate level order traversal
int main() {
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    printf("Level order traversal of binary tree is: ");
    levelOrder(root);

    return 0;
}
