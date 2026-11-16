#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student
{
    int roll;
    char name[30];
    float marks;
    struct Student *next;
};

struct Student *head = NULL;

// Add Student
void add()
{
    struct Student *newnode, *temp;

    newnode = (struct Student*)malloc(sizeof(struct Student));

    printf("Enter Roll No: ");
    scanf("%d", &newnode->roll);

    printf("Enter Name: ");
    scanf("%s", newnode->name);

    printf("Enter Marks: ");
    scanf("%f", &newnode->marks);

    newnode->next = NULL;

    if(head == NULL)
        head = newnode;
    else
    {
        temp = head;

        while(temp->next != NULL)
            temp = temp->next;

        temp->next = newnode;
    }

    printf("Student added successfully!\n");
}

// Display Students
void display()
{
    struct Student *temp = head;

    if(head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    printf("\nRoll No\tName\tMarks\n");

    while(temp != NULL)
    {
        printf("%d\t%s\t%.2f\n",
               temp->roll, temp->name, temp->marks);

        temp = temp->next;
    }
}

// Search Student
void search()
{
    int r;
    struct Student *temp = head;

    printf("Enter Roll No to search: ");
    scanf("%d", &r);

    while(temp != NULL)
    {
        if(temp->roll == r)
        {
            printf("Student Found!\n");
            printf("Name: %s\n", temp->name);
            printf("Marks: %.2f\n", temp->marks);
            return;
        }

        temp = temp->next;
    }

    printf("Student not found!\n");
}

// Update Student
void update()
{
    int r;
    struct Student *temp = head;

    printf("Enter Roll No to update: ");
    scanf("%d", &r);

    while(temp != NULL)
    {
        if(temp->roll == r)
        {
            printf("Enter New Name: ");
            scanf("%s", temp->name);

            printf("Enter New Marks: ");
            scanf("%f", &temp->marks);

            printf("Record updated!\n");
            return;
        }

        temp = temp->next;
    }

    printf("Student not found!\n");
}

// Delete Student
void delete()
{
    int r;
    struct Student *temp = head, *prev = NULL;

    printf("Enter Roll No to delete: ");
    scanf("%d", &r);

    while(temp != NULL && temp->roll != r)
    {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL)
    {
        printf("Student not found!\n");
        return;
    }

    if(prev == NULL)
        head = temp->next;
    else
        prev->next = temp->next;

    free(temp);

    printf("Student deleted!\n");
}

// Sort Students
void sort()
{
    struct Student *i, *j;
    int choice, order, tempRoll;
    float tempMarks;
    char tempName[30];

    printf("Sort by: 1.Roll No  2.Marks: ");
    scanf("%d", &choice);

    printf("Order: 1.Ascending  2.Descending: ");
    scanf("%d", &order);

    for(i = head; i != NULL; i = i->next)
    {
        for(j = i->next; j != NULL; j = j->next)
        {
            int swap = 0;

            if(choice == 1)
            {
                if(order == 1 && i->roll > j->roll)
                    swap = 1;

                if(order == 2 && i->roll < j->roll)
                    swap = 1;
            }
            else
            {
                if(order == 1 && i->marks > j->marks)
                    swap = 1;

                if(order == 2 && i->marks < j->marks)
                    swap = 1;
            }

            if(swap == 1)
            {
                tempRoll = i->roll;
                i->roll = j->roll;
                j->roll = tempRoll;

                tempMarks = i->marks;
                i->marks = j->marks;
                j->marks = tempMarks;

                strcpy(tempName, i->name);
                strcpy(i->name, j->name);
                strcpy(j->name, tempName);
            }
        }
    }

    printf("Records sorted successfully!\n");
}

int main()
{
    int choice;

    while(1)
    {
        printf("\n--- Student Record Management ---\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Sort Students\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: add(); break;
            case 2: display(); break;
            case 3: search(); break;
            case 4: update(); break;
            case 5: delete(); break;
            case 6: sort(); break;

            case 7:
                printf("Program Ended!");
                return 0;

            default:
                printf("Invalid Choice!\n");
        }
    }
}