#include <stdio.h>
#include <iostream>
#define INF 99999
int cost[20][20];

int prims(int n)
{
    int i,j,k, minCost=0, min ,visited[20], x=-1,y=-1;

    for (i = 1;i <= n;i++)
        visited[i] = 0;
    visited[1] = 1;

    for (k = 1;k < n;k++)
    {
        min = INF;
        for (i = 1;i <= n;i++)
            for (j = 1;j <= n;j++)
                if (cost[i][j] != INF && visited[i] && !visited[j] && cost[i][j] < min)
                {
                    min = cost[i][j];
                    x = i;
                    y = j;
                }
        printf("Edge %d: (%d --> %d) [Cost: %d]\n", k, x, y, min);
        visited[y] = 1;
        minCost += min; 
    }

    return minCost;

}
int main()
{
    int n, i, j;
    printf("Enter number of vertices: ");
    scanf_s("%d", & n);

    printf("Enter adjacency matrix:\n");
    
    for(i=1;i<=n;i++)
        for (j = 1;j <= n;j++)
        {
            scanf_s("%d", &cost[i][j]);
            if (i == j)
                cost[i][j] = 0;
            else if (cost[i][j] == 0 && i != j)
                cost[i][j] = INF;
        }

    printf("Minimum Cost: %d", prims(n));
    return 0;

}

/*
0 2 0 6 0
2 0 3 8 5
0 3 0 0 7
6 8 0 0 9
0 5 7 9 0
*/
