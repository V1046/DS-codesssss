This program implements a fixed-size hash table of size 10 using the division method and linear probing to resolve collisions. It supports Insert, Search, Delete, and Display operations. 

#include <stdio.h>

#define SIZE 10

int hashTable[SIZE];

/* Hash function using Division Method */
int hashFunction(int key)
{
    return key % SIZE;
}

/* Insert a key */
void insert(int key)
{
    int index = hashFunction(key);
    int start = index;

    while (hashTable[index] != -1)
    {
        index = (index + 1) % SIZE;

        if (index == start)
        {
            printf("Hash table is full!\n");
            return;
        }
    }

    hashTable[index] = key;
    printf("Key %d inserted at index %d\n", key, index);
}

/* Search a key */
void search(int key)
{
    int index = hashFunction(key);
    int start = index;

    while (hashTable[index] != -1)
    {
        if (hashTable[index] == key)
        {
            printf("Key %d found at index %d\n", key, index);
            return;
        }

        index = (index + 1) % SIZE;

        if (index == start)
            break;
    }

    printf("Key %d not found\n", key);
}

/* Delete a key */
void deleteKey(int key)
{
    int index = hashFunction(key);
    int start = index;

    while (hashTable[index] != -1)
    {
        if (hashTable[index] == key)
        {
            hashTable[index] = -1;
            printf("Key %d deleted\n", key);
            return;
        }

        index = (index + 1) % SIZE;

        if (index == start)
            break;
    }

    printf("Key %d not found\n", key);
}

/* Display hash table */
void display()
{
    int i;

    printf("\nHash Table:\n");

    for (i = 0; i < SIZE; i++)
    {
        if (hashTable[i] == -1)
            printf("Index %d : Empty\n", i);
        else
            printf("Index %d : %d\n", i, hashTable[i]);
    }
}

/* Main function */
int main()
{
    int choice, key, i;

    /* Initialize hash table */
    for (i = 0; i < SIZE; i++)
        hashTable[i] = -1;

    while (1)
    {
        printf("\n--- Hash Table Menu ---\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Delete\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter key: ");
                scanf("%d", &key);
                insert(key);
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
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}



