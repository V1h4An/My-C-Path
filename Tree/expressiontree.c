#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>  // For checking if a character is a digit


// Define structure for a node
struct Node {
    char data;                 // data can be operator (+, -, *, /) or operand (number)
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(char data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Structure for a stack of tree nodes
struct Stack {
    int top;
    struct Node* items[100];
};

// Initialize stack
struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    return stack;
}

// Push to stack
void push(struct Stack* stack, struct Node* node) {
    stack->items[++stack->top] = node;
}

// Pop from stack
struct Node* pop(struct Stack* stack) {
    return stack->items[stack->top--];
}

// Function to construct expression tree from a postfix expression
struct Node* constructTree(char postfix[]) {
    struct Stack* stack = createStack();
    struct Node *t, *t1, *t2;

    // Traverse the postfix expression
    for (int i = 0; postfix[i] != '\0'; i++) {
        // If operand, create a new node and push it to stack
        if (isdigit(postfix[i])) {
            t = createNode(postfix[i]);
            push(stack, t);
        }
        // If operator, pop two nodes and make them children of the operator node
        else {
            t = createNode(postfix[i]);

            // Pop two nodes
            t1 = pop(stack);    // Right child
            t2 = pop(stack);    // Left child

            // Make them children
            t->right = t1;
            t->left = t2;

            // Push the current node back to stack
            push(stack, t);
        }
    }

    // The only element left in the stack is the root of the expression tree
    t = pop(stack);
    return t;
}

// Function to evaluate the expression tree
int evaluate(struct Node* root) {
    // Base case: if the node is a leaf (operand), return its value
    if (root->left == NULL && root->right == NULL)
        return root->data - '0';  // Convert character digit to int

    // Recursively evaluate left and right subtrees
    int leftEval = evaluate(root->left);
    int rightEval = evaluate(root->right);

    // Apply the operator
    if (root->data == '+')
        return leftEval + rightEval;
    if (root->data == '-')
        return leftEval - rightEval;
    if (root->data == '*')
        return leftEval * rightEval;
    if (root->data == '/')
        return leftEval / rightEval;

    return 0;
}

int main() {
    char postfix[] = "34+52-*";  // Postfix expression
    struct Node* root = constructTree(postfix);

    printf("Result of expression evaluation: %d\n", evaluate(root));  // Output: 21
    return 0;
}
