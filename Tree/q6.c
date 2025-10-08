/*Check if Two Trees are Identical: Write a function to check if two binary trees
are identical. The function should return true if both trees have the same structure
and the same node values, and false otherwise.*/

#include <stdio.h>
#include <stdlib.h>

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

int checkidentical(struct Node* root, struct Node* root1) {
    if (root == NULL && root1 == NULL)
        return 1;
    if (root == NULL || root1 == NULL)
        return 0;
    return (root->data == root1->data) &&
           checkidentical(root->left, root1->left) &&
           checkidentical(root->right, root1->right);
}

int main() {
    struct Node* root = createnode(2);
    struct Node* a = createnode(4);
    struct Node* b = createnode(5);
    struct Node* c = createnode(11);
    struct Node* d = createnode(19);
    struct Node* e = createnode(20);
    struct Node* f = createnode(6);
    struct Node* g = createnode(7);
    struct Node* h = createnode(9);
    root->left = a;
    root->right = b;
    root->left->left = c;
    root->left->left->left = d;
    root->left->left->right = e;
    root->right->left = f;
    root->right->right = g;
    root->right->right->left = h;

    struct Node* root1 = createnode(2);
    struct Node* a1 = createnode(4);
    struct Node* b1 = createnode(5);
    struct Node* c1 = createnode(11);
    struct Node* d1 = createnode(19);
    struct Node* e1 = createnode(20);
    struct Node* f1 = createnode(6);
    struct Node* g1 = createnode(7);
    struct Node* h1 = createnode(0);
    root1->left = a1;
    root1->right = b1;
    root1->left->left = c1;
    root1->left->left->left = d1;
    root1->left->left->right = e1;
    root1->right->left = f1;
    root1->right->right = g1;
    root1->right->right->left = h1;

    if (checkidentical(root, root1))
        printf("The trees are identical.\n");
    else
        printf("The trees are not identical.\n");

    return 0;
}
