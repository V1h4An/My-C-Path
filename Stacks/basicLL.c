/*
Stacks are FILO first in last out.

Push: Add an item to the top of the stack,pushing the rest to the bottom.

Pop: Remove the item from the top of the stack,pulling the rest one place up.

Peek (or Top): Get the value of the top item without removing it.

IsEmpty: Check whether the stack is empty.

IsFull (optional, for fixed-size stacks): Check whether the stack is full.*/

#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

typedef struct Stack{
    Node*top;
}Stack;

void initialise(Stack*stack){
    stack->top=NULL;
}

int isempty(Stack*stack){
    return stack->top==NULL;
}

void push(Stack*stack,int item){
    Node*newnode=(Node*)malloc(sizeof(Node));
    if(newnode==NULL){
        printf("stack overflow");
        return;
    }
    newnode->data=item;
    newnode->next=stack->top;
    stack->top=newnode;
    printf("%d was pushed to the stack",item);
}

int pop(Stack*stack){
    if(isempty(stack)){
        printf("stack Underflow");
        return -1;
    }
    Node*temp=stack->top;
    int poppeddata=temp->data;
    stack->top=stack->top->next;
    free(temp);
    return poppeddata;
}

int peek(Stack*stack){
    if(isempty(stack)){
        printf("stack Underflow");
        return -1;
    }
    return stack->top->data;
}

int main(){
    Stack stack;
    initialise(&stack);
    
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("\n%d popped from stack\n", pop(&stack));
    printf("Top element is %d\n", peek(&stack));

    return 0;
}