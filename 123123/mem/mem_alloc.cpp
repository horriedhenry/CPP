// #include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

void _malloc() {
    int *a = (int *)malloc(sizeof(int));
    float *b = (float *)malloc(sizeof(float));
    *a = 12;
    *b = 12.22;
    // a = nullptr; // use nullptr before calling free() , else it just prints a
    // random value.
    // free(a);
    std::cout << *a << std::endl;
    std::cout << *b << std::endl;
}

void malloc_array() {
    int size = 3;
    int *arr = (int *)malloc(size * sizeof(int));
    // can use this to loop through
    for (int i = 0; i < 3; i++) {
        *(arr + i) = 1;
    }
    // or just use the normal way.
    for (int i = 0; i < 3; i++) {
        std::cout << arr[i] << " ";
    }
    free(arr);
    arr = nullptr;
    // for (int i = 0; i < 3; i++) {
    //     std::cout << arr[i] << " ";
    // }
}

void malloc_string() {
    std::string *str = (std::string *)malloc(sizeof(std::string));
    *str = "this is a string";
    int size = str->size();
    std::cout << *str << std::endl;
    std::cout << size << std::endl;
}

void malloc_vector() {
    std::vector<int> *arrs =  (std::vector<int> *)malloc(sizeof(std::vector<int>));
}

void _new() {
    int *arr = new int[3]; // int array of size 3
    for (int i = 0; i < 3; i++) {
        *(arr + i) = 1;
    }
    delete[] arr;
    arr = nullptr;
}


void vector() {
    std::vector<int> *arrs = new std::vector<int>;
    arrs->push_back(222);
    for (auto it = arrs->begin(); it != arrs->end(); ++it) {
        std::cout << *it << " ";
    }
    delete arrs;
    arrs = nullptr;
}

void str() {
    std::string* str = new std::string;
    *str = "string";
    int size = str->size();
    std::cout << *str << std::endl;
    std::cout << size << std::endl;
    delete str;
    str = nullptr;
}

int main (int argc, char *argv[]) {
    malloc_array();
    return 0;
}
