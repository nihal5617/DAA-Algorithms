#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define INF INT_MAX;

int min(int a, int b)
{
    return (a > b) ? b : a;
}

int shortestDist(int **graph, int N)
{
    int dist[N];
    dist[N - 1] = 0;
    for (int i = N - 2; i >= 0; i--)
    {
        dist[i] = INF;
        for (int j = i; j < N; j++)
        {
            if (graph[i][j] == INT_MAX)
                continue;
            dist[i] = min(dist[i], graph[i][j] + dist[j]);
        }
    }
    return dist[0];
}

int main()
{
    int vertices, n;
    printf("Enter the number of vertices : ");
    scanf("%d", &vertices);
    int **graph = (int **)malloc(vertices * sizeof(int *));

    // take graph input  printf("Enter the adjacency matrix :\n");

    for (int i = 0; i < vertices; i++)
    {
        graph[i] = (int *)malloc(vertices * sizeof(int));
        for (int j = 0; j < vertices; j++)
        {
            scanf("%d", &n);
            if (n == 0)
                graph[i][j] = INT_MAX;
            else
                graph[i][j] = n;
        }
    }
    printf("Shortest distance is %d", shortestDist(graph, vertices));
    return 0;
}
