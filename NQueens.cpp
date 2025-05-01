#include <stdio.h>
#include <math.h>
int x[20];

void drawBoard(int n)
{
    int i, j;
    for (i = 1;i <= n;i++)
    {
        printf("\n");
        for (j = 1;j <= n;j++)
            if (x[i] == j)
                printf(" Q ");
            else
                printf(" _ ");
    }
    printf("\n");
}
int place(int k, int i)
{
    int j;
    for(j=1;j<=k-1;j++)
        if (x[j] == i || (abs(x[j] - i) == abs(j - k)))
            return 0;
    return 1;
}

void nQueen(int k, int n)
{
    int i, j;
    for (i = 1;i <= n;i++)
    {
        if (place(k, i))
        {
            x[k] = i;
            if (k == n)
            {
                printf("\n");
                for (j = 1;j <= n;j++)
                    printf("%d ", x[j]);
                drawBoard(n);
            }
            else
                nQueen(k + 1, n);
        }
    }
}
int main()
{
    int n;
    printf("Enter board dimensions: ");
    scanf_s("%d", &n);
    nQueen(1, n);
}
