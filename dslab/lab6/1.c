/*Write a menu driven program to create a stack using array and perform the 
following operation using function
a. Push
b. Pop
c. check stack is empty or not
d. check stack is full or not
e. display stack elements
*/
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

void traverse(Stack* stack) {
    if (isempty(stack)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = stack->top; i >= 0; i--) {
        printf("%d ", stack->arr[i]);
    }
    printf("\n");
}

int main()
{
    Stack stack;
    initstack(&stack);
    int choice;

    while(1)
    {
        printf("\nMenu:\n");
        printf("1.Push \n");
        printf("2.Pop \n");
        printf("3.Check if stack is empty \n");
        printf("4.Check if stack is full \n");
        printf("5. Traverse the stack \n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
        case (1):{
            int x;
            printf("enter element");
            scanf("%d",&x);
            push(&stack,x);
            break;
        }
        case(2):{
            printf("%d was popped from the stack\n",pop(&stack));
            break;
        }
        case(3):{
            if(isempty(&stack)){
            printf("Stack is empry");
            }
            else{
                printf("Stack is not empty");
            }
            break;
        }
        case(4):{
            if(isfull(&stack))
            {
                printf("stack is full");
            }
            else{
                printf("stack is not full");
            }
            break;
        }
        case(5):{
            traverse(&stack);
            break;
        }
        case(6):
            exit(0);
        default:
            printf("enter valid choice");
        }
    }
return 0;
}