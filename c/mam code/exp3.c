Implement a real-time event processing system using a Queue data structure. The 
system 
should support the following features: 
• Add an Event: When a new event occurs, it should be added to the event queue. 
• Process the Next Event: The system should process and remove the event that 
has 
been in the queue the longest. 
• Display Pending Events: Show all the events currently waiting to be processed. 
• Cancel an Event: An event can be canceled if it has not been processed. 
#include <stdio.h> 
#include <string.h> 
#define MAX 5 
char queue[MAX][50]; 
int front = -1, rear = -1; 
// Add Event 
void addEvent() 
{ 
if (rear == MAX - 1) 
{ 
} 
printf("Event Queue is Full!\n"); 
return; 
    char event[50]; 
 
    printf("Enter event name: "); 
    scanf(" %[^\n]", event); 
 
    if (front == -1) 
        front = 0; 
 
    rear++; 
    strcpy(queue[rear], event); 
 
    printf("Event added successfully!\n"); 
} 
 
// Process Next Event 
void processEvent() 
{ 
    if (front == -1 || front > rear) 
    { 
        printf("No event to process!\n"); 
        return; 
    } 
 
    printf("Processing Event: %s\n", queue[front]); 
    front++; 
 
    if (front > rear) 
    { 
        front = -1; 
        rear = -1; 
    } 
} 
 
// Display Pending Events 
void displayEvents() 
{ 
    if (front == -1) 
    { 
        printf("No pending events!\n"); 
        return; 
    } 
 
    printf("\nPending Events:\n"); 
 
    for (int i = front; i <= rear; i++) 
    { 
        printf("%d. %s\n", i - front + 1, queue[i]); 
    } 
} 
 
// Cancel an Event 
void cancelEvent() 
{ 
    if (front == -1) 
    { 
        printf("No events to cancel!\n"); 
        return; 
    } 
 
    char event[50]; 
    int found = -1; 
 
    printf("Enter event name to cancel: "); 
    scanf(" %[^\n]", event); 
 
    for (int i = front; i <= rear; i++) 
    { 
        if (strcmp(queue[i], event) == 0) 
        { 
            found = i; 
            break; 
        } 
    } 
 
    if (found == -1) 
    { 
        printf("Event not found!\n"); 
        return; 
    } 
 
    // Shift events to remove cancelled event 
    for (int i = found; i < rear; i++) 
    { 
        strcpy(queue[i], queue[i + 1]); 
    } 
 
    rear--; 
 
    if (rear < front) 
    { 
        front = -1; 
        rear = -1; 
    } 
 
    printf("Event cancelled successfully!\n"); 
} 
 
// Main Function 
int main() 
{ 
    int choice; 
 
    do 
    { 
        printf("\n===== EVENT PROCESSING SYSTEM =====\n"); 
        printf("1. Add Event\n"); 
        printf("2. Process Next Event\n"); 
        printf("3. Display Pending Events\n"); 
        printf("4. Cancel an Event\n"); 
        printf("5. Exit\n"); 
 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
 
        switch (choice) 
        { 
            case 1: 
                addEvent(); 
                break; 
 
            case 2: 
                processEvent(); 
                break; 
 
            case 3: 
                displayEvents(); 
                break; 
 
            case 4: 
                cancelEvent(); 
                break; 
 
            case 5: 
                printf("Exiting program...\n"); 
                break; 
 
            default: 
                printf("Invalid choice!\n"); 
        } 
 
    } while (choice != 5); 
 
    return 0; 
} 
 