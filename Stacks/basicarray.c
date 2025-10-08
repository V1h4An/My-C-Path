/*
Stacks are FILO first in last out.

Push: Add an item to the top of the stack,pushing the rest to the bottom.

Pop: Remove the item from the top of the stack,pulling the rest one place up.

Peek (or Top): Get the value of the top item without removing it.

IsEmpty: Check whether the stack is empty.

IsFull (optional, for fixed-size stacks): Check whether the stack is full.*/

#include<stdio.h>
#include<stdlib.h>

#define MAX 100

typedef struct Stack{
    int arr[MAX];
    int top;
}Stack;

void initstack(Stack* stack)
{
    stack->top=-1; 
}

int isfull(Stack*stack)
{
   return stack->top==MAX-1;
}

int isempty(Stack*stack)
{
    return stack->top==-1;
}

void push(Stack* stack,int element)
{
    if(isfull(stack))
    {
        printf("stack overflow");
        return;
    }
    stack->arr[++(stack->top)] = element;
    printf("%d is pushed to the stack\n",element);
}

int pop(Stack* stack)
{
    if(isempty(stack))
    {
        printf("stack is empty");
        return -1;
    }
    return stack->arr[(stack->top)--];
}

int peek(Stack*stack)
{
    if(isempty(stack))
    {
        printf("stack is empty");
        return -1;
    }
    return stack->arr[(stack->top)];
}

int main()
{
    Stack stack;
    
    initstack(&stack);

    push(&stack,10);
    push(&stack,20);
    push(&stack,30);
    push(&stack,40);
    push(&stack,50);

    printf("%d was popped from the stack\n",pop(&stack));
    printf("%d is the top element of the stack\n",peek(&stack));
    
return 0;
}