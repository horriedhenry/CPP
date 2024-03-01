#include <iostream>

// https://www.learncpp.com/cpp-tutorial/variable-assignment-and-initialization/

#define endl std::endl

int main (int argc, char *argv[]) {
    int var = 1; // copy initialization of value 5
    int var_1(5);
    // List initialization methods (C++11) (preferred)
    int var_{3};
    int e{}; // empty
    return 0;
}
