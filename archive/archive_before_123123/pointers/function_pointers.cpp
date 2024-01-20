#include <iostream>
#include <string>

// Instead of pointing to a data value a function pointer points to a function,
// with a return value.

int add(int a, int b) { return a + b; }

int main (int argc, char *argv[]) {
    int (*addPtr)(int, int) = add;
    int sum = (*addPtr)(2,3);
    std::cout<<sum<<"\n";
    return 0;
}
