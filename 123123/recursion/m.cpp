#include <iostream>

void recursion(int x) {
    if (x > 5) {
        return;
    }
    recursion(x + 1);
    std::cout << x << std::endl;
}

int factorial(int n) {
    if (n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
    // 5 * factorial(4) called by fac(5) from main() function
    // 4 * factorial(3) called by fac(4)
    // 3 * factorial(2) called by fac(3)
    // 2 * factorial(1) called by fac(2)
    // factorial(1) return 1 from where it is called that is 2 * fac(1)
    // 2 * 1 = 2 (return this to fac(3))
    // 3 * 2 = 6 (return this to fac(4))
    // 4 * 6 = 24 (return this to fac(5))
    // 5 * 24 = 120 (return this to fac(5) in main function) 
    // finally prints 120.
}

int main (int argc, char *argv[]) {
    // recursion(1);
    std::cout << factorial(5) << std::endl;
    return 0;
}
