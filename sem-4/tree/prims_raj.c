#include <stdio.h>
#include <stdlib.h>
#define MAX 10

// CREATE ADJECANCY MATRIX.
void create(int adj[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("\nWeight of edge from v%d to v%d?: ", i + 1, j + 1);
            scanf(" %d", &adj[i][j]);
        }
    }
}

// DISPLAY ADJECANCY MATRIX.
void display(int adj[MAX][MAX], int n)
{
    printf("\n\n");
    printf("_");
    for (int i = 0; i < n; i++)
        printf("v%d ", i + 1);
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("v%d ", i + 1);
        for (int j = 0; j < n; j++)
        {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}

// Prims Algorithm
int minimum(int weightss[], int visited[])
{
    int min = 999, min_index;
    for (int v = 0; v < MAX; v++)
        if (!visited[v] && weightss[v] < min)
        {
            min = weightss[v];
            min_index = v;
        }
    return min_index;
}

int print_mst(int parent[], int graph[MAX][MAX], int n)
{
    printf("Edge \tweights\n");
    for (int i = 1; i < n; i++)
        printf("%d - %d \t%d \n", parent[i] + 1, i + 1, graph[i][parent[i]]);
}

void prims_algo(int graph[MAX][MAX], int n)
{
    int parent[n], weights[n], visited[n];
    // create F and set keys to 999;
    for (int i = 0; i < n; i++)
    {
        weights[i] = 999;
        visited[i] = 0;
    }
    // storing first weights as 0;
    weights[0] = 0;
    // as we are starting form first node , we are storing it as -1;
    parent[0] = -1;
    for (int count = 0; count < n - 1; count++)
    {
        // getting the vertex which has lowest weight.
        int next = minimum(weights, visited);
        visited[next] = 1;
        for (int v = 0; v < n; v++)
        {
            if (graph[next][v] && !visited[v] && graph[next][v] < weights[v])
            {
                parent[v] = next;
                weights[v] = graph[next][v];
            }
        }
    }
    print_mst(parent, graph, n);
}
int main()
{
    int c, n, r = 1;
    int adj[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);
    create(adj, n);
    display(adj, n);
    prims_algo(adj, n);
}