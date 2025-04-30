#include <stdio.h>
#define MAX 20

void swap(int a[], int num1, int num2) {
	int temp = a[num1];
	a[num1] = a[num2];
	a[num2] = temp;
}

int partition(int a[], int low, int high)
{
	int pivot = a[low], i = low, j = high;
	while (i < j)
	{
		while (a[i] <= pivot && i < high)
			i++;
		while (a[j] > pivot && j > low )
			j--;
		if (i < j)
			swap(a,i, j);
	}
	swap(a, low,j);
	return j;
}
void quickSort(int a[], int low, int high)
{
	if (low < high)
	{
		int partitionPoint = partition(a, low, high);
		quickSort(a, low, partitionPoint - 1);
		quickSort(a, partitionPoint + 1, high);
	}
	//display();
}

int main() 
{
	int n, a[MAX], i;
	printf("Number of elements: ");
	scanf_s("%d", &n);
	printf("Enter elements: ");
	for (i = 0; i < n; i++)
		scanf_s("%d", &a[i]);
	quickSort(a, 0, n - 1);
	printf("After sorting: ");
	for (i = 0; i < n; i++) 
		printf("%d ", a[i]);
}
