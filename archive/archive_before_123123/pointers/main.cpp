#include <iostream>
using namespace std;

int main (int argc, char *argv[]) {
    int a = 12;
    int* aPtr = &a;
    std::cout<<"The value of aPtr : "<<aPtr<<endl;
    std::cout<<"Deference aPtr (i.e *aPtr): "<<*aPtr<<endl;
    std::cout<<"The address of aPtr : "<<&aPtr<<endl;
    std::cout<<"Deference aPtr : "<<*&aPtr<<endl;
    std::cout<<"Deference *&aPtr(i.e **&aPtr) : "<<**&aPtr<<endl;
    int b = 13;
    aPtr = &b;
    cout<<"Deference aPtr after (aPtr = &b) : "<<*aPtr<<endl;
    aPtr = nullptr;
    free(aPtr);
}
