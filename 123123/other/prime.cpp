#include <iostream>

bool is_prime(int num) {
    int count = 0;
    if (num < 2) {
        return false; // any number less than 2 is not prime
    }
    for (int i = 2; i < 9; i++) {
        if (num % i == 0) {
            count++;
        }
        if (count > 1) {
            return false;
        }
    }
    return true;
}

int main (int argc, char *argv[]) {
    int input = 6;
    if(is_prime(input)) {
        std::cout << input << " is prime " << std::endl;
    } else {
        std::cout << input << " is not prime " << std::endl;
    }
    return 0;
}
