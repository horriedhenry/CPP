#include <iostream>

int main (int argc, char *argv[]) {
    int a = 1;
    int b{2};
    int c = {2};
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;
    return 0;
}
