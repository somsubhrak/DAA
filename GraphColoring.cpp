#include <stdio.h>
int cost[20][20], x[20], m, n, count = 0;

void write()
{
	count++;
	printf("Solution %d:\n", count);
	for (int i = 1; i <= n; i++)
		printf("Vertex %d -> Color %d\n", i, x[i]);
	printf("\n");
}
void nextValue(int k)
{
	int j;
	while (1)
	{
		x[k] = (x[k] + 1) % (m + 1);
		if (x[k] == 0)
			return;
		for (j = 1;j <= n;j++)
			if (cost[k][j] && x[k] == x[j])
				break;
		if (j == n + 1)
			return;
	}
}
void mColoring(int k)
{
	int i;
	while (1)
	{
		nextValue(k);
		if (x[k] == 0)
			return;
		if (k == n)
			write();
		else
			mColoring(k + 1);
	}
}

int main()
{
	int i, j;
	printf("Number of vertices and colors: ");
	scanf_s("%d %d", &n, &m);
	printf("Enter adjacency matrix:\n");
	for(i=1;i<=n;i++)
		for (j = 1; j <= n; j++)
			scanf_s("%d", &cost[i][j]);

	for (i = 1;i <= n;i++)
		x[i] = 0;

	mColoring(1);
	printf("Total solutions: %d", count);


}
