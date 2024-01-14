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

void print_fibonacci(int count) {
    int curr, prev, next;
    std::cout << 0 << " " << 1 << " ";
    curr = 1;
    prev = 0;
    for (int i = 0; i < count - 2; i++) {
        // count - 2 because 0 and 1 are constant, and 0, 1 are already printed those
        // so use -2 , if -2 is not used this loop prints 0 1 and count no.of 
        // fibonacci numbers
        next = curr + prev;
        prev = curr;
        curr = next;
        std::cout << next << " ";
    }
    std::cout << std::endl;
}

void print_fibonacci_(int count) {
    int first = 0, second = 1, next;
    std::cout << first << " " << second << " ";
    for (int i = 0; i < count - 2; i++) {
        // count - 2 because 0 and 1 are constant, and 0, 1 are already printed those
        // so use -2 , if -2 is not used this loop prints 0 1 and count no.of 
        // fibonacci numbers
        next = first + second;
        first = second;
        second = next;
        std::cout << next << " ";
    }
    std::cout << std::endl;
}

int main (int argc, char *argv[]) {
    // recursion(1);
    // std::cout << factorial(5) << std::endl;
    print_fibonacci(10);
    return 0;
}
