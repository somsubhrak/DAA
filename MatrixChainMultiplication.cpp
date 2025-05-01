#include <stdio.h>
#define MAX 10
#define INF 9999
int n = 0, p[MAX], m[MAX][MAX], s[MAX][MAX];

void M_C_O()
{
	int i, l, j, k, q = 0;

	for (i = 1;i <= n;i++)
		m[i][i] = 0;

	for (l = 2;l <= n;l++)
		for (i = 1;i <= n - l + 1;i++)
		{
			j = i + l - 1;
			m[i][j] = INF;
			for (k = i;k <= j - 1;k++)
			{
				q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (m[i][j] > q)
				{
					m[i][j] = q;
					s[i][j] = k;
				}
			}
		}
}

void P_O_P(int i, int j)
{
	if (i == j)
		printf("A%d ", i);
	else
	{
		printf("(");
		P_O_P(i, s[i][j]);
		P_O_P((s[i][j]) + 1, j);
		printf(")");
	}
}
int main()
{
	int i, j, d;
	printf("Enter number of dimensions : ");
	scanf_s("%d", &d);
	n = d - 1;
	printf("Enter dimension matrix: \n");
	for (i = 0;i < d;i++)
		scanf_s("%d", &p[i]);

	M_C_O();

	printf("M matrix: \n");
	for (i = 1;i <= n;i++)
	{
		for (j = 1;j <= n;j++)
			if (i <= j)
				printf("%d	", m[i][j]);
			else
				printf("	");
		printf("\n");
	}

	printf("S matrix: \n");
	for (i = 1;i <= n;i++)
	{
		for (j = 1;j <= n;j++)
		{
			if (i < j)
				printf("%d	", s[i][j]);
			else
				printf("	");

		}
		printf("\n");
	}

	P_O_P(1, n);

	printf("\nMinimum Cost: %d", m[1][n]);

}