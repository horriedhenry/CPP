#include <stdio.h>
#include <stdbool.h>

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
    // loop
    //  int factorial = n;
    //  n--;
    //  for (int i = n; i >= 1; i--)
    //  {
    //      factorial *= i;
    //  }
    //  printf("%d * %d", n, n * fact(n - 1));
    return (n * fact(n - 1));
}

int main(void)
{
    int in;
    scanf_s("%d", &in);
    int ans;
    ans = fact(in);
    printf("%d", ans);
    return 0;
}

// Debub
// #include <stdio.h>
// #include <stdlib.h>

// int factorial(int n);

// int main()
// {
//     int num;
//     int fact_val;
//     printf("Enter the number for which you are going to compute the factorial:");
//     scanf("%d", &num);

//     fact_val = factorial(num);

//     printf("The factorial of the given number is %d\n", fact_val);

//     return 0;
// }

// int factorial(int n)
// {
//     int factorial_val;
//     if (n == 1)
//         return 1;
//     else
//     {
//         factorial_val = factorial(n - 1) * n;
//         printf("Debugger-%d\n", factorial_val);
//     }
//     return factorial_val;
// }
