#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left, *right;
};

struct Node* insert(struct Node *root, int value)
{
    if(root == NULL)
    {
        struct Node *newnode;
        newnode = (struct Node*)malloc(sizeof(struct Node));

        newnode->data = value;
        newnode->left = NULL;
        newnode->right = NULL;

        return newnode;
    }

    if(value < root->data)
        root->left = insert(root->left, value);

    else if(value > root->data)
        root->right = insert(root->right, value);

    else
        printf("Duplicate value not allowed!\n");

    return root;
}

// Search
void search(struct Node *root, int value)
{
    if(root == NULL)
    {
        printf("Element not found!\n");
        return;
    }

    if(root->data == value)
        printf("Element found!\n");

    else if(value < root->data)
        search(root->left, value);

    else
        search(root->right, value);
}

// Find Minimum
struct Node* findMin(struct Node *root)
{
    while(root->left != NULL)
        root = root->left;

    return root;
}

// Delete
struct Node* deleteNode(struct Node *root, int value)
{
    if(root == NULL)
    {
        printf("Element not found!\n");
        return root;
    }

    if(value < root->data)
        root->left = deleteNode(root->left, value);

    else if(value > root->data)
        root->right = deleteNode(root->right, value);

    else
    {
        if(root->left == NULL)
            return root->right;

        else if(root->right == NULL)
            return root->left;

        struct Node *temp = findMin(root->right);

        root->data = temp->data;

        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

// Inorder
void inorder(struct Node *root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Preorder
void preorder(struct Node *root)
{
    if(root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder
void postorder(struct Node *root)
{
    if(root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Main
int main()
{
    struct Node *root = NULL;
    int choice, value;

    while(1)
    {
        printf("\n\n--- BINARY SEARCH TREE ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Inorder\n");
        printf("5. Preorder\n");
        printf("6. Postorder\n");
        printf("7. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;

            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                printf("Delete operation completed.\n");
                break;

            case 3:
                printf("Enter value to search: ");
                scanf("%d", &value);
                search(root, value);
                break;

            case 4:
                printf("Inorder: ");
                inorder(root);
                break;

            case 5:
                printf("Preorder: ");
                preorder(root);
                break;

            case 6:
                printf("Postorder: ");
                postorder(root);
                break;

            case 7:
                return 0;

            default:
                printf("Invalid choice!");
        }
    }
}