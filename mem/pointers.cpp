#include <iostream>

void func_copy(int var) {
    // will copy the argument passed to this function and any chages made 
    // will be in this scope . that is it can only be used in this func.
    var = 20;
    std::cout << var << std::endl;
    // if we pass a = 12 to this func and do var = 20 , it's not gonna modify
    // the original value
}

void func(int* var) {
    // pass by address does not copy value for the sake of this func() call
    *var = 20;
}

void pointer_basic() {
    int a = 12;
    int* aptr = &a;
    std::cout << &a << std::endl; // prints the address of a i.e (0x7ffe5e152c04)
    std::cout << aptr << std::endl; // prints the value of aptr which is (0x7ffe5e152c04)
    // aptr is storing the address of a so it prints the address that it is storing.
    func_copy(a);
    std::cout << a << std::endl; // prints 12
    func(&a);
}

void de_reference() {
    int a = 12;
    int* aptr = &a;
    std::cout << aptr << std::endl; // prints the value of aptr which is (0x7ffe5e152c04)
    // aptr is storing the address of a so it prints the address that it is storing.
    // De Referencing
    // we use '*' to access the value that is stored at a certain memory location.
    std::cout << *(aptr) << std::endl;
    // aptr = 20;
    // or
    // std::cout << &aptr << std::endl;
    std::cout << *&aptr << std::endl; // de_reference the address using *(&aptr)
}

void de_reference_aptr() {
    int a = 12;
    int* aptr = &a;
    std::cout << "a : " << a << std::endl;
    std::cout << "aptr : " << aptr << std::endl;
    std::cout << "address of aptr &aptr : " << &aptr << std::endl;
    std::cout << "dereference the address of aptr using *&aptr : " << *(&aptr) << std::endl;
    // using this `&aptr` we get the address of aptr and then when we do 
    // *(&aptr) we dereference the address and this gives the value that is being
    // stored at the memory location of `aptr`.
    // and aptr is storing the memory location of a so we get the address of a
    // when we do *(&aptr)
    // and we get the memory location of aptr when we do &aptr.
    std::cout << "dereference the address of aptr using **&aptr : " << **(&aptr) << std::endl;
    // &aptr - gives the memory address of aptr
    // *&aptr - gives the value that is stored by aptr at it's memeory location.
    // **&aptr - first dereference this *&aptr, which gives memory location of a
    // and then dereference the memory location to get the value of a
    // using **&aptr
}

void free_nullptr() {
    int a = 12;
    int* aptr = &a;
    std::cout << "aptr : " << *aptr << std::endl;
    aptr = nullptr;
    free(aptr);
}

void pass_by_reference(int* address) {
    // accepts a address  (pass by reference)
    std::cout << *address << "\n";
}

int main (int argc, char *argv[]) {
    int a = 10;
    pass_by_reference(&a);
    return 0;
}
