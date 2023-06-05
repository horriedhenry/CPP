#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // int a = 10;
    // int b = a++; // post increment
    // printf("post increment\n");
    // printf("a : %d\n", a);
    // printf("b : %d\n", b);

    // int a = 10;
    // int b = ++a;
    // printf("pre increment\n");
    // // int b = ++a; // pre increment
    // printf("a : %d\n", a);
    // printf("b : %d", b);

    // ex1:
    // int i = 1;
    // i = i++ + ++i;
    // printf("i = %d\n", i);

    // ex 2:
    //  int i = 1;
    //  int j = 2;
    //  int k;
    //  k = i + j + i++ + j++ + ++i + ++j;
    //  printf("i : %d \tj : %d\tk : %d\t", i, j, k);

    // ex 3 :
    // int i = 0;
    // i = (i++) - (--i) + (++i) - (i--);
    // printf("i = %d ", i);
    // return 0;

    int a = 5;
    int b = 5;
    printf("%d", a == b);
}
