#include <stdio.h>

#define N 30

int main() {
    int board[N + 1];
    int dist[N + 1];
    int queue[N * N];
    int front = 0, rear = 0;
    int i, current, next, dice;

    /* Initialize board */
    for (i = 1; i <= N; i++) {
        board[i] = i;
        dist[i] = -1;
    }

    /* Ladders */
    board[3] = 22;
    board[5] = 8;
    board[11] = 26;
    board[20] = 29;

    /* Snakes */
    board[27] = 1;
    board[21] = 9;
    board[17] = 4;
    board[19] = 7;

    /* Start BFS from square 1 */
    queue[rear++] = 1;
    dist[1] = 0;

    while (front < rear) {
        current = queue[front++];

        if (current == N)
            break;

        /* Try all dice values from 1 to 6 */
        for (dice = 1; dice <= 6; dice++) {
            next = current + dice;

            if (next > N)
                break;

            /* Apply snake or ladder */
            next = board[next];

            /* Visit each square only once */
            if (dist[next] == -1) {
                dist[next] = dist[current] + 1;
                queue[rear++] = next;
            }
        }
    }

    if (dist[N] != -1)
        printf("Minimum dice throws = %d\n", dist[N]);
    else
        printf("Destination cannot be reached.\n");

    return 0;
}

7. Sample Output
Minimum dice throws = 3
The minimum is 3 throws. One possible sequence is:
1
3 → 22
Ladder
Throw 1
22
28
