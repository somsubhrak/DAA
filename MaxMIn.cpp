#include <stdio.h>
#define SIZE 20
int MAX, MIN;

void MaxMin(int a[], int i, int j)
{
    
    if (i == j)
        MAX = MIN = a[i];
    else if(i==j-1)
        if (a[i] > a[j])
        {
            MAX = a[i];
            MIN = a[j];
        }
        else
        {
            MAX = a[j];
            MIN = a[i];
        }
    else
    {
        int mid = (i + j) / 2;
        MaxMin(a, i, mid);
        int lmax = MAX, lmin = MIN;
        MaxMin(a, mid+1, j);
        MAX = (MAX > lmax) ? MAX : lmax;
        MIN = (MIN < lmin) ? MIN : lmin;
    }
}

int main() 
{
    int a[SIZE],
        i, n;
    printf("Total elements: ");
    scanf_s("%d", &n);
    printf("Enter elements: ");
    for (i = 0; i < n; i++)
        scanf_s("%d", &a[i]);
    MaxMin(a, 0, n - 1);
    printf("Maximum: %d\nMinimum: %d", MAX, MIN);
}