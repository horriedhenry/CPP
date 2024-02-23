#include <iostream>

void recursion(int x) {
    if (x > 5) {
        return;
    }
    std::cout << x << std::endl; // pre recursion
    recursion(x + 1);
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

int sum_n_digits_rec(int n) {
    // using loop
    // int res = 0;
    // for (int i = 1; i <= n; i++) {
    //     res += i;
    // }
    // std::cout << res << "\n";
    if (n == 0) {
        return 0;
    }
    return n + sum_n_digits_rec(n - 1);
}

int n_raised_p(int n, int p) {
    // using loop
    // int res = 1;
    // for (int i = 0; i < p; i++) {
    //     res *= n;
    // }
    // std::cout << res << "\n";
    if (p == 0) {
        return 1;
    }
    return n * n_raised_p(n, p - 1);
}

int main (int argc, char *argv[]) {
    // std::cout << sum_n_digits_rec(4) << std::endl;
    // std::cout << n_raised_p(2,3) << "\n";
    recursion(1);
    return 0;
}
