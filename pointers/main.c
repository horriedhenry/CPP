#include <stdio.h>

int main (int argc, char *argv[]) {
    int a = 12;
    int* aPtr = &a;
    printf("Address of a is : %p\n", aPtr);
    printf("Address of aPtr is : %p\n", &aPtr);
    printf("Address of a using &a : %p", &a);
}
