#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int key, value;
    struct Node *next;
};

struct Node *table[10];

// Insert
void insert()
{
    int key, value;
    int index;
    struct Node *temp, *newnode;

    printf("Enter key: ");
    scanf("%d", &key);

    printf("Enter value: ");
    scanf("%d", &value);

    index = key % 10;

    temp = table[index];

    while(temp != NULL)
    {
        if(temp->key == key)
        {
            temp->value = value;
            printf("Value updated!\n");
            return;
        }
        temp = temp->next;
    }

    newnode = (struct Node*)malloc(sizeof(struct Node));

    newnode->key = key;
    newnode->value = value;
    newnode->next = table[index];

    table[index] = newnode;

    printf("Inserted successfully!\n");
}

// Search
void search()
{
    int key, index;
    struct Node *temp;

    printf("Enter key to search: ");
    scanf("%d", &key);

    index = key % 10;
    temp = table[index];

    while(temp != NULL)
    {
        if(temp->key == key)
        {
            printf("Key found!\n");
            printf("Value: %d\n", temp->value);
            return;
        }

        temp = temp->next;
    }

    printf("Key not found!\n");
}

// Delete
void delete()
{
    int key, index;
    struct Node *temp, *prev = NULL;

    printf("Enter key to delete: ");
    scanf("%d", &key);

    index = key % 10;
    temp = table[index];

    while(temp != NULL && temp->key != key)
    {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL)
    {
        printf("Key not found!\n");
        return;
    }

    if(prev == NULL)
        table[index] = temp->next;
    else
        prev->next = temp->next;

    free(temp);

    printf("Key deleted successfully!\n");
}

// Display
void display()
{
    int i;
    struct Node *temp;

    printf("\nHash Table:\n");

    for(i = 0; i < 10; i++)
    {
        printf("%d: ", i);

        temp = table[i];

        while(temp != NULL)
        {
            printf("(%d, %d) -> ", temp->key, temp->value);
            temp = temp->next;
        }

        printf("NULL\n");
    }
}

// Main Function
int main()
{
    int choice, i;

    for(i = 0; i < 10; i++)
        table[i] = NULL;

    while(1)
    {
        printf("\n--- HASH TABLE ---\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Delete\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: insert(); break;
            case 2: search(); break;
            case 3: delete(); break;
            case 4: display(); break;

            case 5:
                printf("Program Ended!");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}