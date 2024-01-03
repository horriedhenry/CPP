#include <cstring>
#include <iostream>

/*

input = "abc"
output :
a
ab
abc

similar to pattern printing, rows are equal to len of the input

print suffix
input = "abc"
output :
c
bc
abc

*/

void print_prefix(char str[]) {
    for (int i = 0; i < strlen(str); i++) {
        for (int j = 0; j <= i; j++) {
            std::cout << str[j];
        }
        std::cout << std::endl;
    }
}

void print_suffix(char str[]) {
    int s = strlen(str);
    for (int i = s - 1; i >= 0 ; i--) {
        for (int j = i; j <= s - 1; j++) {
            std::cout << str[j];
        }
        std::cout << std::endl;
    }
}

int main (int argc, char *argv[]) {
    freopen("input", "r", stdin);
    char str[10];
    std::cin >> str;
    print_prefix(str);
    print_suffix(str);
    return 0;
}
