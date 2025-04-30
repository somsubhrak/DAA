#include <stdio.h>
#define MAX 20

int binarySearch(int a[], int l, int u, int key)
{
    int mid = (l + u) / 2;
    if (l > u)
        return -1;
    if (a[mid] == key)
        return mid;
    else if(a[mid]<key)
        return binarySearch(a, mid+1, u, key);
    else
        return binarySearch(a, l, mid-1, key);
}
int main()
{
    int n, a[MAX], i, key;
    printf("Number of elements: ");
    scanf_s("%d", &n);
    printf("Enter elements: ");
    for (i = 0;i < n;i++)
        scanf_s("%d", &a[i]);
    printf("Elements to be searched: ");
    scanf_s("%d", &key);

    i = binarySearch(a, 0, n - 1, key);
    if (i == -1)
        printf("Element not found");
    else
        printf("Element found at position %d", i + 1);
    return 0;
}
