// yeah.......file name could be better
#include <iostream>

void pointer_to_array() {
    int arr[3] = {1, 2, 3};
    int* arrPtr = arr; // arrPtr points to first element in the array.
    // we can use print statement to get the first value
    std::cout << *arrPtr << "\n"; // prints 1
    for (int i = 0; i < 3; i++) {
        std::cout << *(arrPtr + i) << " ";
        // pointer arithmetic
        // when we have (arrPtr + 1) it just moves 4 bytes forward in memory (in case of int)
        // coz int is of size 4 bytes.
        // to print the next value and then dereference it by *(arrPtr + 1) = 2
    }
    std::cout << "\n";
    for (int i = 0; i < 3; i++) {
        std::cout << (arrPtr + i) << std::endl;
        // or we can just prints 3 addressess
        // we get
        // 1
        // 1 2 3
        // 0x7ffcd052f334
        // 0x7ffcd052f338
        // 0x7ffcd052f33c
    }
    // use pointer Arithmetics to print array elements
    // Dont need to declare a new ptr to point to the array coz when we declare
    // an array it points to the memory location of first element. so we can 
    // use it directly.
    for (int i = 0; i < 3; i++) {
        std::cout << *(arr + i) << " ";
    }
    std::cout << "\n";
}

int main (int argc, char *argv[]) {
    pointer_to_array();
    return 0;
}
