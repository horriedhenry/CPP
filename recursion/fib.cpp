#include <iostream>

long long int fib(long long int n) {
    // nth fibonacci number.
    if (n < 2) {
        return n;
        // n == 1 or n == 0 then just return n
    }
    return fib(n - 1) + fib(n - 2);
    // -298632863
    // ./r.sh  83.17s user 0.06s system 99% cpu 1:23.62 total
    // for fib(50)
    // after changing to long long int
    // for fib(50)
    // ./r.sh  84.34s user 0.09s system 99% cpu 1:24.74 total
    // 12586269025
}

void fib_loop(int n) {
    // fib_loop(51) gives : 12586269025
    long long int first = 0, second = 1, next;
    for (int i = 0; i < n - 2; i++) {
        next = first + second;
        first = second;
        second = next;
    }
    std::cout << next << " ";
    std::cout << std::endl;
    // this prints 50th fibonacci number in 
    // ./r.sh  0.19s user 0.02s system 99% cpu 0.211 total
    // 1 2 3 5 8 13 21 34 55 89 144 233 377 610 987 1597 2584 4181 6765 10946 
    // 17711 28657 46368 75025 121393 196418 317811 514229 832040 1346269 2178309 
    // 3524578 5702887 9227465 14930352 24157817 39088169 63245986 102334155 
    // 165580141 267914296 433494437 701408733 1134903170 1836311903 2971215073 
    // 4807526976 7778742049
}

int main (int argc, char *argv[]) {
    std::cout << fib(5) << std::endl;
    // fib_loop(51);
    return 0;
}
