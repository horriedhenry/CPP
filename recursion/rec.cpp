#include <iostream>

void print_first_n_numbers(int n) {
    if (n == 0) {
        return;
    }
    print_first_n_numbers(n - 1);
    std::cout << n << " ";
}

int sum_first_n_numbers(int n) {
    if (n == 0) {
        return 0;
    }
    // return n + sum_first_n_numbers(n - 1); // n is pre recursion
    // or
    std::cout << "pre : " << n << std::endl;
    int curr = sum_first_n_numbers(n - 1);
    std::cout << "post : " << curr << std::endl; // post recursion
    return curr;
}

int n_power_p(int n, int p) {
    if (p == 0) {
        return 1;
    }
    std::cout << "pre : " << p << " " << std::endl; // pre recursion
    int ret = n * n_power_p(n, p - 1);
    std::cout << "post : " << ret << " " << std::endl; // post recursion
    return ret;
}

long long factorial(long long int n) {
    if (n == 0) {
        return 1;
    }
    std::cout << n << " * "; // pre recursion
    int fact = n * factorial(n - 1);
    std::cout << fact << std::endl; // post recursion
    return fact;
}

int main (int argc, char *argv[]) {
    std::cout << factorial(5) << std::endl;
    return 0;
}
