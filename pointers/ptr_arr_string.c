#include <stdio.h>
#include <stdlib.h>

typedef struct House {
    int whatever;
    int whothefuck;
    int whatThefuck;
    int whateverr;
    int whothefuckk;
    int whatThefuckk;
}House;

int main(int argc, char *argv[])
{
    char string[] = "This is a character array";
    char* ptr = string;
    printf("%c", string[0]);
    printf("using *ptr (prints first character of the string) : %c \n", *ptr);
    int arr[3] = {1,2,3};
    int *arrPtr = arr;
    printf("%d", arr[0]);
    printf("using *ptr (prints first element of the array) : %d \n", *arrPtr);
    printf("%c\n", *(ptr + 3));
    printf("sizeof(arrPtr) : %d \n", sizeof(arrPtr));
    printf("sizeof(ptr) : %d \n", sizeof(ptr));
    printf("sizeof(arr) : %d \n", sizeof(arr));
    printf("sizeof(string[]) : %d\n", sizeof(string));
    House house;
    house.whatever = 10;
    house.whatever = 20;
    house.whatever = 30;
    printf("sizeof(house) : %d\n", sizeof(house));
    House* housePtr = &house;
    printf("sizeof(housePtr) : %d\n", sizeof(housePtr));
    return 0;
}
