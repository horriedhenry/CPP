#include <stdio.h>

int fact(int n)
{
    int factorial = 1;
    for (int i = 2; i <= n; i++)
    {
        factorial *= i;
    }
    return factorial;
}

int ncr(int n, int r)
{
    return fact(n) / (fact(r) * fact(n - r));
}

int main(void)
{
    int rows;
    scanf("%d", &rows);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            printf("%d ", ncr(i, j));
        }
        printf("\n");
    }
    return 0;
}
