#include <stdio.h>
#include <math.h>
#include <stdbool.h>

void isPrime(int n)
{
    if (n == 0 || n == 1)
    {
        printf("Non_prime\n");
        return;
    }
    int flag = 0;

    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            // printf("Non-Prime\n");
            flag = 1;
            break;
        }
    }

    if (flag == 0)
    {
        printf("Prime {%d} \n", n);
    }
}

void prime_nbrs()
{
    for (int i = 0; i < 100; i++)
    {
        isPrime(i);
    }
}

int main(void)
{
    return 0;
}
