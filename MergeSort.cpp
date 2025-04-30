#include <stdio.h>
#define MAX 20

void merge(int a[], int low, int mid, int high) {
	int i = low, j = mid + 1, k = low, b[MAX];

	while (i <= mid && j <= high) {
		if (a[i] <= a[j])
			b[k++] = a[i++];
		else
			b[k++] = a[j++];
	}

	while (i <= mid)
		b[k++] = a[i++];

	while (j <= high)
		b[k++] = a[j++];

	for (i = low; i <= high; i++)
		a[i] = b[i];
	//display();
}

void mergesort(int a[],int low, int high) {


	if (low < high) {
		int mid = (low + high) / 2;
		mergesort(a, low, mid);
		mergesort(a, mid + 1, high);
		merge(a, low, mid, high);
	}
}

int main()
{
	int n, a[MAX], i;
	printf("Number of elements: ");
	scanf_s("%d", &n);
	printf("Enter elements: ");
	
	for (i = 0; i < n; i++)
		scanf_s("%d", &a[i]);
	mergesort(a, 0, n - 1);
	
	printf("After sorting: ");
	for (i = 0; i < n; i++) 
		printf("%d ", a[i]);
}
