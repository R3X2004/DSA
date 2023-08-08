#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

// Node structure for a binary tree
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

// Function to recursively mirror the binary tree
void mirrorBinaryTree(struct Node* root) {
    if (root == NULL)
        return;
        
    // Swap the left and right child nodes
    struct Node* temp = root->left;
    root->left = root->right;
    root->right = temp;
    
    // Recursively mirror the left and right subtrees
    mirrorBinaryTree(root->left);
    mirrorBinaryTree(root->right);
}

// Function to perform an inorder traversal of the binary tree
void inorderTraversal(struct Node* root) {
    if (root == NULL)
        return;
    
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

// Main function to test the above functions
int main() {
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    
    printf("Inorder traversal before mirroring: ");
    inorderTraversal(root);
    printf("\n");
    
    mirrorBinaryTree(root);
    
    printf("Inorder traversal after mirroring: ");
    inorderTraversal(root);
    printf("\n");
    
    return 0;
}