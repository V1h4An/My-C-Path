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

void inorder(struct Node*root){
    if(root == NULL)
    return;
    inorder(root->left);
    printf("%d\t",root->data);
    inorder(root->right);
}
void preorder(struct Node*root){
        if(root == NULL)
    return;
    printf("%d\t",root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(struct Node*root){
        if(root == NULL)
    return;
    postorder(root->left);
    postorder(root->right);
    printf("%d\t",root->data);
}

int main(){
    struct Node* root =createnode(2);
    struct Node* a =createnode(4);
    struct Node* b =createnode(5);
    struct Node* c =createnode(11);
    struct Node* d =createnode(19);
    struct Node* e =createnode(20);
    struct Node* f =createnode(6);
    struct Node* g =createnode(7);
    struct Node* h =createnode(9);
    root->left=a;
    root->right=b;
    root->left->left=c;
    root->left->left->left=d;
    root->left->left->right=e;
    root->right->left=f;
    root->right->right=g;
    root->right->right->left=h;

inorder(root);
printf("\n");
preorder(root);
printf("\n");
postorder(root);
return 0; 
}
