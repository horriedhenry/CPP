#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    int n;
    scanf("%d", &n);
    int reverse = 0;
    while (n > 0)
    {
        int lastdigit = n % 10;
        reverse = reverse * 10 + lastdigit;
        n = n / 10;
    }
    printf("%d", reverse);
    return 0;
}
