#include <stdio.h>

int main()
{
    int n, i, j, min, temp, count;
    float salary[100], a[100], b[100];

    // Input
    printf("Enter number of employees: ");
    scanf("%d", &n);

    printf("Enter employee salaries:\n");

    for(i = 0; i < n; i++)
    {
        scanf("%f", &salary[i]);
        a[i] = salary[i];
        b[i] = salary[i];
    }


    // Bubble Sort
    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    printf("\nBubble Sort:\n");
    printf("Ascending Order: ");

    for(i = 0; i < n; i++)
    {
        printf("%.2f ", a[i]);
    }

    printf("\nTop 5 Highest Salaries: ");

    count = n < 5 ? n : 5;

    for(i = n - 1; i >= n - count; i--)
    {
        printf("%.2f ", a[i]);
    }


    // Selection Sort
    for(i = 0; i < n - 1; i++)
    {
        min = i;

        for(j = i + 1; j < n; j++)
        {
            if(b[j] < b[min])
            {
                min = j;
            }
        }

        temp = b[i];
        b[i] = b[min];
        b[min] = temp;
    }

    printf("\n\nSelection Sort:\n");
    printf("Ascending Order: ");

    for(i = 0; i < n; i++)
    {
        printf("%.2f ", b[i]);
    }

    printf("\nTop 5 Highest Salaries: ");

    for(i = n - 1; i >= n - count; i--)
    {
        printf("%.2f ", b[i]);
    }

    return 0;
}