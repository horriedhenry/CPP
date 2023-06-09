#include <iostream>

// Pointer Arithmetic
int main (int argc, char *argv[]) {
    std::string str = "Hello, Iam Underwater";
    std::string* strPtr = &str;
    for(int i = 0; i < str.length(); i++) {
        std::cout<<(*strPtr)[i];
    }

    std::cout<<"Pointer Arithmetic"<<std::endl;
    int arr[3] = {1, 2, 3};
    int* arrPtr = arr;
    // use pointer Arithmetics to print array elements
    for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
        std::cout<<*(arrPtr + i)<<std::endl;
    }
    return 0;
}
