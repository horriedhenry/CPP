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

void pointer_arithmetic() {
    int arr[3] = {4,5,6};
    // addition
    for (int i = 0; i < 3; i++) {
        std::cout << *(arr + i) << " ";
    }
    std::cout << std::endl;
    // print in reverse order
    for (int i = 2; i >= 0; i--) {
        std::cout << *(arr + i) << " ";
    }
}

typedef struct Person {
    int age;
} Person;

void pointer_to_struct_and_ptr_arithmetic() {
    Person arr[100];
    Person* arr_ptr = arr;
    for (int i = 0; i < 100; i++) {
        arr_ptr->age = 12;
        arr_ptr += 1;
    }
    // after the above for loop the arr_ptr reaches to last element so reassign
    // the pointer to point at first memory location of the arr 
    arr_ptr = arr;
    for (int i = 0; i < 100; i++) {
        std::cout << arr_ptr->age << " ";
    }
    std::cout << "\n";
    // or just use the original arr
    for (int i = 0; i < 100; i++) {
        (arr + i)->age = 23;
        // arr[i].age = 12; // or may be use this
    }
    for (int i = 0; i < 100; i++) {
       std::cout << arr[i].age << " "; // use '.' operator when accessing the
        // contents of struct directly.
       std::cout << (arr + i)->age << " "; // when using address use `->`
    }
}

void typecast_void_pointer() {
    int a = 100;
    void* aptr = &a;
    // aptr = nullptr; // use this before calling free()
    // free(aptr);
    std::cout << (int *)aptr << std::endl; // convert void to int pointer
    // prints address at aptr
    std::cout << *(int *)aptr << std::endl; // convert void to int pointer
    // dereference the address, output = 100
    // Output :
    // 0x7ffd46106df4
    // 100
    aptr = nullptr;
    free(aptr);
}

int main (int argc, char *argv[]) {
    pointer_to_struct_and_ptr_arithmetic();
    return 0;
}
