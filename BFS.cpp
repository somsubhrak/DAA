#include <iostream>
#include <stdio.h>

#define MAX 20

int G[MAX][MAX], visited[MAX], n, Q[MAX], front = 0, rear = -1;

void ADD(int w)
{
    Q[++rear] = w;  // Add element to the queue
}

int DELETE()
{
    return Q[front++];  // Remove and return element from the front of the queue
}

void BFS(int v)
{
    int u, w;
    visited[v] = 1;  // Mark the starting vertex as visited
    ADD(v);  // Add the starting vertex to the queue
    while (front <= rear)
    {
        u = DELETE();  // Dequeue
        printf("%d ", u);  // Print visited vertex
        for (w = 1; w <= n; w++)  // Check all adjacent vertices
        {
            if (G[u][w] && !visited[w])  // If there's an edge and the vertex is not visited
            {
                ADD(w);  // Add vertex to the queue
                visited[w] = 1;  // Mark the vertex as visited
            }
        }
    }
}

void BFT()
{
    int i;
    for (i = 1; i <= n; i++)  // Reset all vertices as unvisited
        visited[i] = 0;

    for (i = 1; i <= n; i++)  // Start BFS from each unvisited vertex
        if (!visited[i])
            BFS(i);
}

int main()
{
    int i, j;

    printf("Enter number of vertices: ");
    scanf_s("%d", &n);  // Read the number of vertices

    // Read the adjacency matrix
    printf("Enter the adjacency matrix (use 1 for edge, 0 for no edge):\n");
    for (i = 1; i <= n; i++)  // 1-based indexing for vertices
        for (j = 1; j <= n; j++)
            scanf_s("%d", &G[i][j]);  // Read each element of the adjacency matrix

    printf("Breadth First Traversal (BFT) of the graph:\n");
    BFT();  // Perform breadth-first traversal

    return 0;
}
