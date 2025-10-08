#include <stdio.h>
#include <stdlib.h>

// Define structure for a binary search tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node into a BST
struct Node* insert(struct Node* node, int data) {
    // Base case: If the tree is empty, return a new node
    if (node == NULL) 
        return createNode(data);

    // Recur down the tree
    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);

    // Return the unchanged node pointer
    return node;
}

// Function to search for a value in the BST
struct Node* search(struct Node* root, int data) {
    // Base case: root is null or data is present at root
    if (root == NULL || root->data == data)
        return root;

    // If data is less than the root, search in the left subtree
    if (data < root->data)
        return search(root->left, data);

    // If data is greater than the root, search in the right subtree
    return search(root->right, data);
}

// Function to find the node with the minimum value in a tree (in-order successor)
struct Node* findMin(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

// Function to delete a node from a BST
struct Node* deleteNode(struct Node* root, int data) {
    if (root == NULL)
        return root;

    // Recur down the tree to find the node to be deleted
    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else {
        // Node to be deleted found

        // Case 1: Node has no children (leaf node)
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }

        // Case 2: Node has one child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Case 3: Node has two children
        // Find the in-order successor (smallest in the right subtree)
        struct Node* temp = findMin(root->right);

        // Copy the in-order successor's value to this node
        root->data = temp->data;

        // Delete the in-order successor
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

// Function to print the BST in-order (left-root-right)
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("In-order traversal of the BST: \n");
    inorder(root);
    printf("\n");

    printf("Deleting node 20\n");
    root = deleteNode(root, 20);
    printf("In-order traversal after deletion: \n");
    inorder(root);
    printf("\n");

    return 0;
}
