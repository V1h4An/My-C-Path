#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

int pathexist(struct Node* root, int x) {
    if (root == NULL)
        return 0;
    if (root->data == x && root->left == NULL && root->right == NULL)
        return 1;
    if (root->data > x)
        return 0;
    return pathexist(root->left, x - root->data) || pathexist(root->right, x - root->data);
}

int main() {
    struct Node* root = createnode(2);
    struct Node* a = createnode(4);
    struct Node* b = createnode(9);
    struct Node* c = createnode(6);
    struct Node* d = createnode(2);
    struct Node* e = createnode(1);
    struct Node* f = createnode(5);
    struct Node* g = createnode(7);
    struct Node* h = createnode(7);

    root->left = a;
    root->right = b;
    a->right = c;
    c->left = d;
    b->left = e;
    b->right = g;
    e->right = f;
    g->left = h;

    int element;
    printf("Enter element to check summation of: ");
    scanf("%d", &element);
    
    if (pathexist(root, element)) {
        printf("Path exists\n");
    } else {
        printf("Path does not exist\n");
    }

    return 0;
}
