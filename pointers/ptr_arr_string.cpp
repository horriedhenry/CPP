#include <iostream>
#include <string>

int main (int argc, char *argv[]) {
    char string[] = "Hello";
    char* ptr = string;
    std::cout<<"using (ptr) prints the entire string in c++ : "<<ptr<<"\n";
    std::cout<<"using (string) prints the entire string in c++ : "<<string<<"\n";
    int arr[3] = {1,2,3};
    int *arrPtr = arr;
    std::cout<<"using (arr) prints the address of the first element of the array : "<<arr<<"\n";
    std::cout<<"using (arrPtr) prints the address of the first element of the array  i.e stored by arrPtr : "<<arrPtr<<"\n";
    std::cout<<"using (*arr) prints the first element of the array : "<<*arr<<"\n";
    std::cout<<"using (*arrPtr) prints the first element of the array : "<<*arrPtr<<"\n";
    std::cout<<"Pointer Arithmetic"<<"\n";
    std::cout<<*(arrPtr + 2)<<"\n";
    std::cout<<*(ptr + 3)<<"\n";
    std::string str = "hello world";
    std::string* strPtr = &str;
    std::cout<<(*strPtr)[3];
    return 0;
}
