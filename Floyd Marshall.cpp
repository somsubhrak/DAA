#include <stdio.h>
#include <iostream>
#define INF 99999
int cost[20][20], A[20][20];

int min(int a, int b)
{
    return a > b ? b : a;
}
void allpairs(int n)
{
    int i,j, k;
    for (i = 1;i <= n;i++)
        for (j = 1;j <= n;j++)
            A[i][j] = cost[i][j];
    
    for (k = 1;k <= n;k++)
        for (i = 1;i <= n;i++)
            for (j = 1;j <= n;j++)
                A[i][j] = min(A[i][j], A[i][k] + A[k][j]);
}

void path(int n)
{
    int i, j;
    printf("V1\tV2\tEdge\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            if (i != j) printf("%d\t%d\t%d\n", i, j, A[i][j]);
}
int main()
{
    int n, i, j;
    printf("Total vertices: ");
    scanf_s("%d", &n);
    printf("Enter adjacency matrix:\n");
    
    for (i = 1; i <= n; i++)
    {
        cost[i][i] = 0;
        for (j = 1;j <= n;j++)
        {
            scanf_s("%d", &cost[i][j]);
            if (cost[i][j] == 0 && i != j)
                cost[i][j] = INF;
        }
    }
    allpairs(n);
    path(n);
}
/*
0 4 11
6 0 2
3 0 0
*/