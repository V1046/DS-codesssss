#include <stdio.h>

int main()
{
    int a[100], n, key, i;
    int low, high, mid, found;

    // Input
    printf("Enter number of customers: ");
    scanf("%d", &n);

    printf("Enter customer IDs: ");

    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Enter customer ID to search: ");
    scanf("%d", &key);


    // Bubble Sort
    for(i = 0; i < n-1; i++)
    {
        for(int j = 0; j < n-i-1; j++)
        {
            if(a[j] > a[j+1])
            {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }


    // Linear Search
    found = 0;

    for(i = 0; i < n; i++)
    {
        if(a[i] == key)
        {
            printf("Linear Search: Element found at index %d\n", i);
            found = 1;
            break;
        }
    }

    if(found == 0)
    {
        printf("Linear Search: Element not found\n");
    }


    // Binary Search
    low = 0;
    high = n-1;
    found = 0;

    while(low <= high)
    {
        mid = (low + high) / 2;

        if(a[mid] == key)
        {
            printf("Binary Search: Element found at index %d\n", mid);
            found = 1;
            break;
        }
        else if(key < a[mid])
        {
            high = mid-1;
        }
        else
        {
            low = mid+1;
        }
    }

    if(found == 0)
    {
        printf("Binary Search: Element not found\n");
    }

    return 0;
}