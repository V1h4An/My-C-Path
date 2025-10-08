#include <stdio.h>
#include <stdlib.h>
#include<limits.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createnode(int data) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    if (!newnode) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

int maximum(int leftmax, int rightmax, int self) {
    if (leftmax >= rightmax && leftmax >= self) return leftmax;
    if (rightmax >= leftmax && rightmax >= self) return rightmax;
    return self;
}

int max(struct Node* root) {
    if (root == NULL)
        return INT_MIN; 
    int leftmax = max(root->left);
    int rightmax = max(root->right);
    int self = root->data;
    return maximum(leftmax, rightmax, self);
}

int main() {
    struct Node* root = createnode(2);
    struct Node* a = createnode(6);
    struct Node* b = createnode(3);
    struct Node* c = createnode(2);
    struct Node* d = createnode(7);
    struct Node* e = createnode(7);
    struct Node* f = createnode(8);
    struct Node* g = createnode(27);
    struct Node* h = createnode(19);
    struct Node* i = createnode(0);
    struct Node* j = createnode(22);

    root->left = a;
    root->right = e;
    a->left = b;
    a->right = c;
    c->left = d;
    e->left = f;
    e->right = g;
    g->left = h;
    g->right = i;
    h->right = j;

    printf("Maximum value in the tree: %d\n", max(root));

    return 0;
}
