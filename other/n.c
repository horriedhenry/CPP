#include <stdio.h>

int sum(int n)
{
    int a = 0;
    for (int i = 1; i <= n; i++)
    {
        a += i;
    }
    // printf("%d ", a);
    return a/2;
}

int main(void)
{
    int n;
    scanf("%d", &n);
    int sum_ = sum(n);
    printf("%d", sum_);
    return 0;
}
