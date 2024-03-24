#include <cstdint>
#include <iostream>

int main (int argc, char *argv[])
{
    int x; // uninitialized

    std::cout << x << "\n"; // either throws an error or prints a garbage value

    // Implementation-defined behavior , might produce different output on a different machine or a different compiler..

    std::cout << sizeof(int) << "\n"; // 4
    std::cout << sizeof(int16_t) << "\n"; // 2
    std::cout << sizeof(int_fast8_t) << "\n"; // 1
    std::cout << sizeof(int_fast16_t) << "\n"; // 8

    return 0;
}
