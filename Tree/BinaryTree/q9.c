/*Check if a Binary Tree is a BST: Implement a function that checks if a binary tree
is a binary search tree (BST). The function should verify that the left subtree has 
only smaller values and the right subtree has only larger values*/

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createnode(int data){
    struct Node* newnode =(struct Node*)malloc(sizeof(struct Node));
    if(!newnode)
        {
        printf("memory allocation failed");
        return NULL;
        }
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

int isleaf(struct Node* root){
    if(root->left==NULL && root->right==NULL)
    return 1;
}

int isBST(struct Node* root){
    if(isleaf(root))
    return 1;
    if(root->left!=NULL && root->data<root->left->data)
    return 0;
    if(root->right!=NULL && root->data<root->right->data)
    return 0;

    return isBST(root->left) && isBST(root->right);
}

int main(){
    struct Node* root =createnode(5);
    struct Node* a =createnode(3);
    struct Node* b =createnode(7);
    struct Node* c =createnode(2);
    struct Node* d =createnode(2);
    struct Node* e =createnode(4);
    struct Node* f =createnode(6);
    struct Node* g =createnode(9);
    struct Node* h =createnode(8);
    root->left=a;
    root->right=b;
    root->left->left=c;
    root->left->left->left=d;
    root->left->left->right=e;
    root->right->left=f;
    root->right->right=g;
    root->right->right->left=h;
if (isBST(root))
        printf("The tree is BST.\n");
    else
        printf("The tree is not BST\n");

    return 0;
}
