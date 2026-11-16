In a company, employee salaries are stored in a list as floating-point numbers. Write a 
Python program that sorts the employee salaries in ascending order using the following two 
algorithms: 
• Selection Sort: Sort the salaries using the selection sort algorithm. 
• Bubble Sort: Sort the salaries using the bubble sort algorithm. 
After sorting the salaries, the program should display top five highest salaries in the company 
 
 
#include <stdio.h> 
 
#define MAX 100 
 
// Function for Selection Sort 
void selectionSort(float a[], int n) 
{ 
    int i, j, min; 
    float temp; 
 
    for (i = 0; i < n - 1; i++) 
    { 
        min = i; 
 
        for (j = i + 1; j < n; j++) 
        { 
            if (a[j] < a[min]) 
                min = j; 
        } 
 
        temp = a[i]; 
        a[i] = a[min]; 
        a[min] = temp; 
    } 
} 
 
// Function for Bubble Sort 
void bubbleSort(float a[], int n) 
{ 
    int i, j; 
    float temp; 
 
    for (i = 0; i < n - 1; i++) 
    { 
        for (j = 0; j < n - i - 1; j++) 
        { 
            if (a[j] > a[j + 1]) 
            { 
                temp = a[j]; 
                a[j] = a[j + 1]; 
                a[j + 1] = temp; 
            } 
        } 
    } 
} 
 
// Function to display array 
void display(float a[], int n) 
{ 
    int i; 
 
    for (i = 0; i < n; i++) 
        printf("%.2f ", a[i]); 
 
    printf("\n"); 
} 
 
// Function to display top five salaries 
void topFive(float a[], int n) 
{ 
    int i, count; 
 
    count = (n < 5) ? n : 5; 
 
    printf("\nTop %d Highest Salaries:\n", count); 
 
    for (i = n - 1; i >= n - count; i--) 
        printf("%.2f\n", a[i]); 
} 
 
int main() 
{ 
    float salaries[MAX]; 
    int n, i; 
 
    printf("Enter number of employees: "); 
    scanf("%d", &n); 
 
    printf("Enter employee salaries:\n"); 
 
    for (i = 0; i < n; i++) 
    { 
        printf("Salary %d: ", i + 1); 
        scanf("%f", &salaries[i]); 
    } 
 
    // Selection Sort 
    selectionSort(salaries, n); 
 
    printf("\nSalaries after Selection Sort (Ascending):\n"); 
    display(salaries, n); 
 
    printf("\n"); 
    topFive(salaries, n); 
 
    // Bubble Sort 
    bubbleSort(salaries, n); 
 
    printf("\nSalaries after Bubble Sort (Ascending):\n"); 
    display(salaries, n); 
 
    printf("\n"); 
    topFive(salaries, n); 
 
    return 0; 
} 
 