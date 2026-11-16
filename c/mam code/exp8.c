
A pizza shop receives multiple orders from several locations. Assume that one pizza boy is
tasked with delivering pizzas in nearby locations, which is represented using a graph. The
time required to reach from one location to another represents node connections. Solve the
problem of delivering a pizza to all customers in the minimum time. Use appropriate data
structures.

#include <stdio.h>

#define N 5
#define INF 999

void dijkstra(int graph[N][N], int source)
{
    int dist[N], visited[N] = {0};
    int parent[N];
    int i, j, u, min;

    for (i = 0; i < N; i++)
    {
        dist[i] = INF;
        parent[i] = -1;
    }

    dist[source] = 0;

    for (i = 0; i < N - 1; i++)
    {
        min = INF;
        u = -1;

        for (j = 0; j < N; j++)
        {
            if (!visited[j] && dist[j] < min)
            {
                min = dist[j];
                u = j;
            }
        }

        if (u == -1)
            break;

        visited[u] = 1;

        for (j = 0; j < N; j++)
        {
            if (graph[u][j] > 0 && !visited[j] &&
                dist[u] + graph[u][j] < dist[j])
            {
                dist[j] = dist[u] + graph[u][j];
                parent[j] = u;
            }
        }
    }

    printf("\nMinimum Delivery Time:\n");

    for (i = 0; i < N; i++)
    {
        if (i == source)
            continue;

        if (dist[i] == INF)
        {
            printf("Location %d is unreachable.\n", i);
        }
        else
        {
            printf("Location %d: %d minutes\n",
                   i, dist[i]);

            printf("Route: ");

            int path[N], count = 0, k = i;

            while (k != -1)
            {
                path[count++] = k;
                k = parent[k];
            }

            for (j = count - 1; j >= 0; j--)
                printf("%d ", path[j]);

            printf("\n");
        }
    }
}

int main()
{
    int graph[N][N] = {
        {0, 4, 2, 0, 0},
        {4, 0, 1, 5, 0},
        {2, 1, 0, 8, 10},
        {0, 5, 8, 0, 2},
        {0, 0, 10, 2, 0}
    };

    printf("Pizza Delivery System\n");
    printf("Location 0 = Pizza Shop\n");

    dijkstra(graph, 0);

    return 0;
}

