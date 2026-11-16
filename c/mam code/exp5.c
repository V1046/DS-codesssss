
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    int roll;
    char name[50];
    float marks;
    struct student *next;
};

struct student *head = NULL;

// Add a student
void addStudent() {
    struct student *newnode, *temp;
    newnode = (struct student *)malloc(sizeof(struct student));

    printf("Enter Roll Number: ");
    scanf("%d", &newnode->roll);

    printf("Enter Name: ");
    scanf(" %49[^\n]", newnode->name);

    printf("Enter Marks: ");
    scanf("%f", &newnode->marks);

    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
    } else {
        temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
    }

    printf("Student added successfully!\n");
}

// Display all students
void display() {
    struct student *temp = head;

    if (head == NULL) {
        printf("No records found!\n");
        return;
    }

    printf("\nRoll No\tName\t\tMarks\n");
    while (temp != NULL) {
        printf("%d\t%s\t\t%.2f\n",
               temp->roll, temp->name, temp->marks);
        temp = temp->next;
    }
}

// Search a student
void searchStudent() {
    int roll;
    struct student *temp = head;

    printf("Enter Roll Number to search: ");
    scanf("%d", &roll);

    while (temp != NULL) {
        if (temp->roll == roll) {
            printf("Roll: %d\nName: %s\nMarks: %.2f\n",
                   temp->roll, temp->name, temp->marks);
            return;
        }
        temp = temp->next;
    }

    printf("Student not found!\n");
}

// Update a student
void updateStudent() {
    int roll;
    struct student *temp = head;

    printf("Enter Roll Number to update: ");
    scanf("%d", &roll);

    while (temp != NULL) {
        if (temp->roll == roll) {
            printf("Enter New Name: ");
            scanf(" %49[^\n]", temp->name);

            printf("Enter New Marks: ");
            scanf("%f", &temp->marks);

            printf("Record updated successfully!\n");
            return;
        }
        temp = temp->next;
    }

    printf("Student not found!\n");
}

// Delete a student
void deleteStudent() {
    int roll;
    struct student *temp = head, *prev = NULL;

    printf("Enter Roll Number to delete: ");
    scanf("%d", &roll);

    while (temp != NULL && temp->roll != roll) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Student not found!\n");
        return;
    }

    if (prev == NULL)
        head = temp->next;
    else
        prev->next = temp->next;

    free(temp);
    printf("Student deleted successfully!\n");
}

// Sort by roll number or marks
void sortStudent() {
    int choice, order, swap;
    float tempMarks;
    int tempRoll;
    char tempName[50];
    struct student *i, *j;

    printf("Sort by: 1.Roll Number  2.Marks: ");
    scanf("%d", &choice);

    printf("Order: 1.Ascending  2.Descending: ");
    scanf("%d", &order);

    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            swap = 0;

            if (choice == 1) {
                if ((order == 1 && i->roll > j->roll) ||
                    (order == 2 && i->roll < j->roll))
                    swap = 1;
            } else if (choice == 2) {
                if ((order == 1 && i->marks > j->marks) ||
                    (order == 2 && i->marks < j->marks))
                    swap = 1;
            }

            if (swap) {
                tempRoll = i->roll;
                i->roll = j->roll;
                j->roll = tempRoll;

                strcpy(tempName, i->name);
                strcpy(i->name, j->name);
                strcpy(j->name, tempName);

                tempMarks = i->marks;
                i->marks = j->marks;
                j->marks = tempMarks;
            }
        }
    }

    printf("Records sorted successfully!\n");
    display();
}

int main() {
    int choice;

    do {
        printf("\n--- Student Record Management ---\n");
        printf("1. Add Student\n");
        printf("2. Delete Student\n");
        printf("3. Update Student\n");
        printf("4. Search Student\n");
        printf("5. Sort Students\n");
        printf("6. Display Students\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: deleteStudent(); break;
            case 3: updateStudent(); break;
            case 4: searchStudent(); break;
            case 5: sortStudent(); break;
            case 6: display(); break;
            case 0: printf("Exiting program.\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 0);

    return 0;
}


