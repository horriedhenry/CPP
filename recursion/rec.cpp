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
    int curr = sum_first_n_numbers(n - 1);
    std::cout << n << " "; // post recursion
    return curr;
}

int main (int argc, char *argv[]) {
    std::cout << sum_first_n_numbers(5) << std::endl;
    return 0;
}
