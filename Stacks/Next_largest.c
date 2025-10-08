/*given an array of integers,for each element,find the next greater element .
[7,1,5,6,2,3,4,9,8,10]*/

#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int top;
    unsigned capacity;
    int* array;
};

struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

int isFull(struct Stack* stack) {
    return stack->top == stack->capacity - 1;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

void push(struct Stack* stack, int item) {
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}

int pop(struct Stack* stack) {
    if (isEmpty(stack))
        return -1;
    return stack->array[stack->top--];
}

int peek(struct Stack* stack) {
    if (isEmpty(stack))
        return -1;
    return stack->array[stack->top];
}

void findNextGreaterElements(int arr[], int n) {
    struct Stack* s = createStack(n);
    int* result = (int*)malloc(n * sizeof(int));
    int i;

    for (i = n - 1; i >= 0; i--) {
        while (!isEmpty(s) && peek(s) <= arr[i]) {
            pop(s);
        }

        if (isEmpty(s)) {
            result[i] = -1;
        } else {
            result[i] = peek(s);
        }

        push(s, arr[i]);
    }

    printf("Original Array  : Next Greater Element\n");
    for (i = 0; i < n; i++) {
        printf("%-15d : %d\n", arr[i], result[i]);
    }

    free(s->array);
    free(s);
    free(result);
}

int main() {
    int arr[] = {7, 1, 5, 6, 2, 3, 4, 9, 8, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    findNextGreaterElements(arr, n);
    return 0;
}

