#include <iostream>
#include <stdio.h>

#define MAX 20

int G[MAX][MAX], visited[MAX], n;

void DFS(int v)
{
    visited[v] = 1;  // Mark the starting vertex as visited
   
    printf("%d ", v);  // Print visited vertex
    for (int w = 1; w <= n; w++)  // Check all adjacent vertices
        if (G[v][w] && !visited[w])  // If there's an edge and the vertex is not visited
            DFS(w);
}

int main()
{
    int i, j, start;

    printf("Enter number of vertices and starting vertex: ");
    scanf_s("%d %d", &n, &start);  // Read the number of vertices

    for (i = 1; i <= n; i++)  // Reset all vertices as unvisited
        visited[i] = 0;

    // Read the adjacency matrix
    printf("Enter the adjacency matrix:\n");
    for (i = 1; i <= n; i++)  
        for (j = 1; j <= n; j++)
            scanf_s("%d", &G[i][j]);  // Read each element of the adjacency matrix

    printf("Depth First Search of the graph:\n");
    DFS(start);  // Perform breadth-first traversal

    return 0;
}
