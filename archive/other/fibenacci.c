#include <stdio.h>

void fib(int n)
{
    int t1 = 0;
    int t2 = 1;
    int nextNbr;
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", t1);
        nextNbr = t1 + t2;
        t1 = t2;
        t2 = nextNbr;
    }
}

int main(void)
{
    fib(10);
    return 0;
}