A call center receives incoming calls, and each call is assigned a unique customer ID. The 
calls are answered in the order they are received. Your task is to simulate the call queue of a 
call center using a queue data structure. 
• addCall(customerID, callTime): Add a call to the queue with the customer ID and the 
call time (in minutes). 
• answerCall(): Answer and remove the first call from the queue. 
• viewQueue(): View all calls currently in the queue without removing them. 
• isQueueEmpty(): Check if the queue is empty. 
 
 
#include <stdio.h> 
 
#define MAX 5 
 
int customerID[MAX]; 
int front = -1; 
int rear = -1; 
 
// Add Call 
void addCall() 
{ 
    int id; 
 
    if (rear == MAX - 1) 
    { 
        printf("Queue is Full!\n"); 
    } 
    else 
    { 
        printf("Enter Customer ID: "); 
        scanf("%d", &id); 
 
        if (front == -1) 
            front = 0; 
 
        rear++; 
        customerID[rear] = id; 
 
        printf("Call added successfully.\n"); 
    } 
} 
 
// Answer Call 
void answerCall() 
{ 
    if (front == -1) 
    { 
        printf("Queue is Empty!\n"); 
    } 
    else 
    { 
        printf("Call answered for Customer ID: %d\n", customerID[front]); 
 
        front++; 
 
        if (front > rear) 
        { 
            front = -1; 
            rear = -1; 
        } 
    } 
} 
 
// View Queue 
void viewQueue() 
{ 
    int i; 
 
    if (front == -1) 
    { 
        printf("Queue is Empty!\n"); 
    } 
    else 
    { 
        printf("Customers in Queue:\n"); 
 
        for (i = front; i <= rear; i++) 
        { 
            printf("%d ", customerID[i]); 
        } 
 
        printf("\n"); 
    } 
} 
 
// Check Queue Empty 
void isQueueEmpty() 
{ 
    if (front == -1) 
        printf("Queue is Empty.\n"); 
    else 
        printf("Queue is Not Empty.\n"); 
} 
 
int main() 
{ 
    int choice; 
 
    while (1) 
    { 
        printf("\n--- CALL CENTER QUEUE ---\n"); 
        printf("1. Add Call\n"); 
        printf("2. Answer Call\n"); 
        printf("3. View Queue\n"); 
        printf("4. Check Queue Empty\n"); 
        printf("5. Exit\n"); 
 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
 
        switch (choice) 
        { 
            case 1: 
                addCall(); 
                break; 
 
            case 2: 
                answerCall(); 
                break; 
 
            case 3: 
                viewQueue(); 
                break; 
 
            case 4: 
                isQueueEmpty(); 
                break; 
 
            case 5: 
                return 0; 
 
            default: 
printf("Invalid choice!\n"); 
} 
} 
return 0; 
}  