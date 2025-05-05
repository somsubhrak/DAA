#include <stdio.h>
#define MAX 20
int d[MAX], p[MAX], id[MAX], slot[MAX];

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void sort(int n)
{

    int i, j;
    for (i = 1; i <= n-1; i++) 
        for (j = 1; j <= n-1; j++) 
            if (p[j + 1] > p[j]) 
            {
                swap(&p[j], &p[j + 1]);
                swap(&id[j], &id[j + 1]);
                swap(&d[j], &d[j + 1]);
            }    
}

int jobSequence(int n)
{
    int i, profit = 0, dmax = d[0],k,c=0;
    for (i = 0;i < n;i++)
        if (d[i] > dmax)
            dmax = d[i];

    for (i = 0;i < dmax;i++)
        slot[i] = -1;

    for (i = 0;i < n;i++)
    {
        k = d[i] - 1;
        while (k >= 0)
        {
            if (slot[k] == -1)
            {
                slot[k] = i;
                profit += p[i];
                c++;
                break;
            }
            k--;
        }
        if (c == dmax)
            break;
    }
    printf("Slots:\n");
    for (i = 0; i < n; i++)
        printf("%d ", slot[i]);
    return profit;

}
int main()
{
    int i, n;
    printf("No. of jobs: ");
    scanf_s("%d", &n);

    printf("Enter job id, profit and deadline: \n");
    for (i = 0; i <n; i++)
        scanf_s("%d %d %d", &id[i], &p[i], &d[i]);

    sort(n);
    printf("Sorted jobs:\n id  profit  deadline\n");

    for (i = 0; i < n; i++)
        printf("  %d    %d    %d\n", id[i], p[i], d[i]);

    printf("\nTotal profit: %d", jobSequence(n));
}
/*
1 20 2
2 15 2
3 10 1
4 5 3
5 1 3
*/

