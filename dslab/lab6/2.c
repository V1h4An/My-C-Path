/*Write a menu driven program to create a stack using linked list and perform the 
following operation using function4
a. Push
b. Pop
c. IsEmpty
d. display the stack elements*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

node* createnode(int data) {
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

void initstack(node** top) {
    *top = NULL;
}


int isempty(node* top) {
    return top == NULL;
}

void push(node** top, int data) {
    node* newnode = createnode(data);
    newnode->next = *top;
    *top = newnode;
}

int pop(node** top) {
    if (isempty(*top)) {
        printf("Stack underflow\n");
        return -1;
    }
    node* temp = *top;
    int popped = temp->data;
    *top = (*top)->next;
    free(temp);
    return popped;
}

void traverse(node* top) {
    if (isempty(top)) {
        printf("Stack is empty\n");
        return;
    }
    node* temp = top;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    node* stack = NULL;
    initstack(&stack);
    int choice;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Check if stack is empty\n");
        printf("4. Traverse the stack\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int x;
                printf("Enter element: ");
                scanf("%d", &x);
                push(&stack, x);
                break;
            }
            case 2: {
                int popped = pop(&stack);
                if (popped != -1) {
                    printf("%d was popped from the stack\n", popped);
                }
                break;
            }
            case 3: {
                if (isempty(stack)) {
                    printf("Stack is empty\n");
                } else {
                    printf("Stack is not empty\n");
                }
                break;
            }
            case 4: {
                traverse(stack);
                break;
            }
            case 5:
                exit(0);
            default:
                printf("Enter a valid choice\n");
        }
    }
    return 0;
}
