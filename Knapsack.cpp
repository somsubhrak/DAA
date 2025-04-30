#include <stdio.h>
#define MAX 50
float w[MAX], r[MAX], x[MAX], p[MAX];
void swap(float* a, float* b)
{
	float temp = *a;
	*a = *b;
	*b = temp;
}
void knapsack(float m, int n)
{
	int i;
	float u, profit = 0.0;
	for (i = 0;i < n;i++)
		x[i] = 0.0;
	u = m;
	for (i = 0;i < n;i++)
	{
		if (w[i] > u)
			break;
		x[i] = 1.0;
		u -= w[i];
	}
	if (i < n)
		x[i] = u / w[i];

	for (i = 0;i < n;i++)
		profit += (p[i] * x[i]);

	printf("The profit: %.2f", profit);
}

void main()
{
	int i, j, n;
	float m;
	printf("Enter number of items and max capacity: ");
	scanf_s("%d %f", &n, &m);

	printf("Enter weight and profit of items: ");

	for (i = 0;i < n;i++)
	{
		scanf_s("%f %f", &w[i], &p[i]);
		r[i] = (p[i] / w[i]);
	}

	for (i = 0;i < n - 1;i++)
	{
		for (j = 0;j < n - i - 1;j++)
		{
			if (r[j] < r[j + 1])
			{
				swap(&r[j], &r[j + 1]);
				swap(&w[j], &w[j + 1]);
				swap(&p[j], &p[j + 1]);
			}
		}
	}
	printf("Sorted arrays: \n r	 w	p\n");
	for (i = 0;i < n;i++)
		printf("%.2f	%.2f	%.2f\n", r[i], w[i], p[i]);

	knapsack(m, n);
	printf("\nSolution array: \n");
	for (i = 0;i < n;i++)
		printf("%.2f ", x[i]);



}