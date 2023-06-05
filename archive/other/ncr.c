#include <stdio.h>

int fact(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    int factorial = n;
    n--;
    for (int i = n; i >= 1; i--)
    {
        factorial *= i;
    }
    return factorial;
}

int main(void)
{
    int n, r;
    scanf("%d %d", &n, &r);
    int ans = fact(n) / (fact(r) * fact(n - r));
    printf("%d ", ans);
    return 0;
}
