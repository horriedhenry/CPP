#include <stdio.h>

[[deprecated]]
void server() {
    printf("This is deprecated");
}

int main (int argc, char *argv[]) {
    [[deprecated]] int a = 12;
    server();
    return 0;
}
