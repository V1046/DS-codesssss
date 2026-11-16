In an e-commerce system, customer account IDs are stored in a list, and you are tasked with 
writing a program that implements the following: 
• Linear Search: Check if a particular customer account ID exists in the list. 
• Binary Search: Implement Binary search to find if a customer account ID exists, 
improving the search efficiency over the basic linear 
 
 
 
 
#include <stdio.h> 
 
int linearSearch(int arr[], int n, int key) 
{ 
    int i; 
 
    for (i = 0; i < n; i++) 
    { 
        if (arr[i] == key) 
            return i; 
    } 
 
    return -1; 
} 
 
int binarySearch(int arr[], int n, int key) 
{ 
    int low = 0, high = n - 1, mid; 
 
    while (low <= high) 
    { 
        mid = (low + high) / 2; 
 
        if (arr[mid] == key) 
            return mid; 
        else if (key < arr[mid]) 
            high = mid - 1; 
        else 
            low = mid + 1; 
    } 
 
    return -1; 
} 
 
int main() 
{ 
    int customerID[100]; 
    int n, i, key; 
    int linearResult, binaryResult; 
 
    printf("Enter number of customers: "); 
    scanf("%d", &n); 
 
    printf("Enter customer account IDs:\n"); 
 
    for (i = 0; i < n; i++) 
    { 
        printf("Customer %d ID: ", i + 1); 
        scanf("%d", &customerID[i]); 
    } 
 
    printf("\nEnter customer ID to search: "); 
    scanf("%d", &key); 
 
    /* Linear Search */ 
    linearResult = linearSearch(customerID, n, key); 
 
    if (linearResult != -1) 
        printf("\nLinear Search: Customer ID %d found at position %d.\n", 
               key, linearResult + 1); 
    else 
        printf("\nLinear Search: Customer ID %d not found.\n", key); 
 
    /* Sort IDs before Binary Search */ 
    for (i = 0; i < n - 1; i++) 
    { 
        int j, temp; 
 
        for (j = 0; j < n - i - 1; j++) 
        { 
            if (customerID[j] > customerID[j + 1]) 
            { 
                temp = customerID[j]; 
                customerID[j] = customerID[j + 1]; 
                customerID[j + 1] = temp; 
            } 
        } 
    } 
 
    printf("\nCustomer IDs after sorting:\n"); 
    for (i = 0; i < n; i++) 
        printf("%d ", customerID[i]); 
 
    /* Binary Search */ 
    binaryResult = binarySearch(customerID, n, key); 
 
    if (binaryResult != -1) 
        printf("\n\nBinary Search: Customer ID %d found.\n", key); 
    else 
        printf("\n\nBinary Search: Customer ID %d not found.\n", key); 
 
    return 0; 
} 
 
 