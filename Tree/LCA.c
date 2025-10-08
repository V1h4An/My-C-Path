#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* createnode(int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

struct node* findLCA(struct node* root, int n1, int n2) {
    if (root == NULL) return NULL;
    
    
    if (root->data == n1 || root->data == n2) {
        return root;
    }

    
    struct node* leftLCA = findLCA(root->left, n1, n2);
    struct node* rightLCA = findLCA(root->right, n1, n2);

   
    if (leftLCA && rightLCA) return root;

   
    return (leftLCA != NULL) ? leftLCA : rightLCA;
}

int main() {
    struct node* root = createnode(1);
    struct node* a = createnode(2);
    struct node* b = createnode(3);
    struct node* c = createnode(4);
    struct node* d = createnode(5);
    struct node* e = createnode(6);
    struct node* f = createnode(7);
    struct node* g = createnode(2);
    struct node* h = createnode(3);
    struct node* i = createnode(6);
    struct node* j = createnode(7);
    struct node* k = createnode(9);
    struct node* l = createnode(8);
    struct node* m = createnode(10);
    struct node* n = createnode(11);
    struct node* o = createnode(2);

    root->left = a;
    root->right = b;
    a->left = c;
    a->right = d;
    b->left = e;
    b->right = f;
    c->left = g;
    c->right = h;
    d->left = i;
    d->right = j;
    e->left = k;
    e->right = l;
    f->left = m;
    f->right = n;
    n->right = o;

    struct node* lca = findLCA(root, 9, 10);
    if (lca != NULL) {
        printf("LCA of 9 and 10 is %d\n", lca->data);
    } else {
        printf("LCA does not exist\n");
    }

    return 0;
}
