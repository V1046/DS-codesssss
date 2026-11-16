Simple C Program: Hash Table Using Chaining
Aim: To implement a hash table of size 10 using the division method as a hash function and chaining to handle collisions. The program performs Insert, Search, Delete, and Display operations.

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

struct Node {
    int key;
    int value;
    struct Node *next;
};

struct Node *table[SIZE];

// Division method hash function
int hash(int key) {
    return key % SIZE;
}

// Insert key-value pair
void insert(int key, int value) {
    int index = hash(key);
    struct Node *temp = table[index];

    // Update value if key already exists
    while (temp != NULL) {
        if (temp->key == key) {
            temp->value = value;
            printf("Value updated successfully.\n");
            return;
        }
        temp = temp->next;
    }

    // Create a new node
    struct Node *newnode =
        (struct Node *)malloc(sizeof(struct Node));

    if (newnode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    newnode->key = key;
    newnode->value = value;

    // Insert at the beginning of the chain
    newnode->next = table[index];
    table[index] = newnode;

    printf("Key inserted successfully.\n");
}

// Search for a key
void search(int key) {
    int index = hash(key);
    struct Node *temp = table[index];

    while (temp != NULL) {
        if (temp->key == key) {
            printf("Key = %d, Value = %d\n",
                   temp->key, temp->value);
            return;
        }
        temp = temp->next;
    }

    printf("Key not found.\n");
}

// Delete a key
void deleteKey(int key) {
    int index = hash(key);
    struct Node *temp = table[index];
    struct Node *prev = NULL;

    while (temp != NULL) {
        if (temp->key == key) {
            if (prev == NULL)
                table[index] = temp->next;
            else
                prev->next = temp->next;

            free(temp);
            printf("Key deleted successfully.\n");
            return;
        }

        prev = temp;
        temp = temp->next;
    }

    printf("Key not found.\n");
}

// Display the hash table
void display() {
    int i;
    struct Node *temp;

    printf("\nHash Table:\n");

    for (i = 0; i < SIZE; i++) {
        printf("[%d] -> ", i);
        temp = table[i];

        while (temp != NULL) {
            printf("(%d, %d) -> ",
                   temp->key, temp->value);
            temp = temp->next;
        }

        printf("NULL\n");
    }
}

// Main function
int main() {
    int choice, key, value;

    do {
        printf("\n--- Hash Table Menu ---\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Delete\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key and value: ");
                scanf("%d %d", &key, &value);
                insert(key, value);
                break;

            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                search(key);
                break;

            case 3:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                deleteKey(key);
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Program terminated.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 5);

    return 0;
}


