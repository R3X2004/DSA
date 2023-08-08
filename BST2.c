#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node in BST
struct Node *insertNode(struct Node *root, int data)
{
    if (root == NULL)
    {
        return createNode(data);
    }
    else if (data < root->data)
    {
        root->left = insertNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insertNode(root->right, data);
    }
    return root;
}

// Function to search for a node in BST
struct Node *searchNode(struct Node *root, int data)
{
    if (root == NULL || root->data == data)
    {
        return root;
    }
    if (data < root->data)
    {
        return searchNode(root->left, data);
    }
    return searchNode(root->right, data);
}

// Function to find the minimum element in BST
struct Node *findMin(struct Node *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    else if (root->left != NULL)
    {
        return findMin(root->left);
    }
    return root;
}

// Function to find the maximum element in BST
struct Node *findMax(struct Node *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    else if (root->right != NULL)
    {
        return findMax(root->right);
    }
    return root;
}

// Function to delete a node from BST
struct Node *deleteNode(struct Node *root, int data)
{
    if (root == NULL)
    {
        return root;
    }
    else if (data < root->data)
    {
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = deleteNode(root->right, data);
    }
    else
    {
        // Node found, perform deletion
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            root = NULL;
        }
        else if (root->left == NULL)
        {
            struct Node *temp = root;
            root = root->right;
            free(temp);
        }
        else if (root->right == NULL)
        {
            struct Node *temp = root;
            root = root->left;
            free(temp);
        }
        else
        {
            struct Node *temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

// Function to traverse the tree in inorder
void inorderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Function to traverse the tree in preorder
void preorderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Function to traverse the tree in postorder
void postorderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

int main()
{
    struct Node *root = NULL;
    int choice, data;

    do
    {
        printf("Menu:\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Find Minimum\n");
        printf("4. Find Maximum\n");
        printf("5. Delete\n");
        printf("6. Inorder Traversal\n");
        printf("7. Preorder Traversal\n");
        printf("8. Postorder Traversal\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
            printf("Exiting the program...\n");
            break;
        case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            root = insertNode(root, data);
            printf("Node inserted successfully.\n");
            break;
        case 2:
            printf("Enter data to search: ");
            scanf("%d", &data);
            if (searchNode(root, data) != NULL)
            {
                printf("Node found.\n");
            }
            else
            {
                printf("Node not found.\n");
            }
            break;
        case 3:
        {
            struct Node *minimum = findMin(root);
            if (minimum != NULL)
            {
                printf("Minimum element in BST: %d\n", minimum->data);
            }
            else
            {
                printf("BST is empty.\n");
            }
            break;
        }
        case 4:
        {
            struct Node *maximum = findMax(root);
            if (maximum != NULL)
            {
                printf("Maximum element in BST: %d\n", maximum->data);
            }
            else
            {
                printf("BST is empty.\n");
            }
            break;
        }
        case 5:
            printf("Enter data to delete: ");
            scanf("%d", &data);
            root = deleteNode(root, data);
            printf("Node deleted successfully.\n");
            break;
        case 6:
            printf("Inorder Traversal: ");
            inorderTraversal(root);
            printf("\n");
            break;
        case 7:
            printf("Preorder Traversal: ");
            preorderTraversal(root);
            printf("\n");
            break;
        case 8:
            printf("Postorder Traversal: ");
            postorderTraversal(root);
            printf("\n");
            break;
        default:
            printf("Invalid choice!\n");
            break;
        }
    } while (choice != 0);

    return 0;
}