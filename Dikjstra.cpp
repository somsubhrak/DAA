#include <stdio.h>
#include <iostream>
#define SIZE 20
#define INF 99999

int dist[SIZE], cost[SIZE][SIZE], pred[SIZE];

void djikstra(int n, int v)
{
	int i, k,u=-1, status[SIZE], w, min;

	for (i = 1;i <= n;i++)
	{
		status[i] = 0;
		dist[i] = INF;
		pred[i] = -1;
	}
	dist[v] = 0;

	for (k = 1;k < n;k++)
	{
		min = INF;
		for(w=1;w<=n;w++)
			if (dist[w] < min && status[w] == 0)
			{
				min = dist[w];
				u = w;
			}

		status[u] = 1;

		for(w=1;w<=n;w++)
			if (cost[u][w] != INF && status[w] == 0 && (dist[u] + cost[u][w] < dist[w]))
			{
				dist[w] = dist[u] + cost[u][w];
				pred[w] = u;
			}
	}
}

void path(int n, int v)
{
	int i;
	for (i = 1;i <= n;i++)
		if (i != v)
			printf("%d --> %d = %d (Predecessor: %d)\n", v, i, dist[i], pred[i]);

}

int main()
{
	int i, j, n, v;
	
	printf("Number of Vertices & Source Vertex: ");
	scanf_s("%d %d", &n, &v);
	
	printf("Enter cost Matrix: \n");
	for(i=1;i<=n;i++)
		for (j = 1;j <= n;j++)
		{
			scanf_s("%d", &cost[i][j]);
			if(cost[i][j] == 0)
				cost[i][j] = INF;
		}

	djikstra(n, v);
	path(n, v);
	return 0;

}

