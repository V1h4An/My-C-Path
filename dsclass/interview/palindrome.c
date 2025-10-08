/*Use a Queue and Stack to check if given string is a palindrome*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000 // Maximum size of the Queue and Stack

typedef struct {
    char word[MAX];
    int top;
} Stack;

typedef struct {
    char word[MAX];
    int front, rear;
} Queue;

void initStack(Stack* stack) {
    stack->top = -1;
}

char isEmptyStack(Stack* stack) {
    return stack->top == -1;
}

char isFullStack(Stack* stack) {
    return stack->top == MAX - 1;
}

void push(Stack* stack, char letter) {
    if (isFullStack(stack)) {
        printf("Stack overflow\n");
        return;
    }
    stack->word[++(stack->top)] = letter;
    printf("%c is pushed into the stack\n", letter);
}

char pop(Stack* stack) {
    if (isEmptyStack(stack)) {
        printf("Stack underflow\n");
        return '\0';
    }
    return stack->word[(stack->top)--];
}

void initQueue(Queue* queue) {
    queue->front = 0;
    queue->rear = 0;
}

char isEmptyQueue(Queue* queue) {
    return queue->front == queue->rear;
}

char isFullQueue(Queue* queue) {
    return queue->rear == MAX;
}

void enqueue(Queue* queue, char letter) {
    if (isFullQueue(queue)) {
        printf("Queue overflow\n");
        return;
    }
    queue->word[queue->rear++] = letter;
    printf("%c is enqueued into the queue\n", letter);
}

char dequeue(Queue* queue) {
    if (isEmptyQueue(queue)) {
        printf("Queue underflow\n");
        return '\0';
    }
    return queue->word[queue->front++];
}

int isPalindrome(char* str) {
    Stack stack;
    Queue queue;
    initStack(&stack);
    initQueue(&queue);

    // Enqueue and push all characters
    for (int i = 0; i < strlen(str); i++) {
        enqueue(&queue, str[i]);
        push(&stack, str[i]);
    }

    // Compare characters from queue and stack
    while (!isEmptyQueue(&queue)) {
        if (dequeue(&queue) != pop(&stack)) {
            return 0; // Not a palindrome
        }
    }
    return 1; // Palindrome
}



int main() {
    char str[] = "madam";
    if (isPalindrome(str)) {
        printf("\"%s\" is a palindrome.\n", str);
    } else {
        printf("\"%s\" is not a palindrome.\n", str);
    }
    return 0;
}
