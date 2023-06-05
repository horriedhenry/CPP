// ternary operator or condition operator
// syntax : condition ? x : y; if condition return true choose x else y
#include <stdio.h>

int main(void)
{
    int a = 10, b = 5;
    int c = a == b ? a + b : a - b;
    printf("%d ", c);
    // int d = (1, 2, 3);
    // printf("%d", d);
    return 0;
}
