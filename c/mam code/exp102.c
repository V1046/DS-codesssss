This is a simple implementation using arrays for both the stack and queue.

#include <stdio.h>
#include <string.h>

#define MAX 100

int main() {
    char str[MAX];
    char stack[MAX], queue[MAX];
    int top = -1;
    int front = 0, rear = -1;
    int i, palindrome = 1;
    int n;

    printf("Enter a string: ");
    scanf("%99s", str);

    n = strlen(str);

    /* Push and enqueue characters */
    for (i = 0; i < n; i++) {
        stack[++top] = str[i];
        queue[++rear] = str[i];
    }

    /* Compare stack and queue characters */
    while (top >= 0 && front <= rear) {
        if (stack[top--] != queue[front++]) {
            palindrome = 0;
            break;
        }
    }

    if (palindrome)
        printf("%s is a palindrome.\n", str);
    else
        printf("%s is not a palindrome.\n", str);

    return 0;
}

7. Sample Output
Example 1: Palindrome
Enter a string: MADAM
MADAM is a palindrome.
Example 2: Not a palindrome
Enter a string: HELLO
HELLO is not a palindrome.
Example 3: Another palindrome
Enter a string: LEVEL
LEVEL is a palindrome.
