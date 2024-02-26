#include <iostream>

[[deprecated]]
void server() {
    std::cout << "this is deprecated" << std::endl;
}

int main (int argc, char *argv[]) {
    [[deprecated]] int var{2};
    [[maybe_unused]] int not_used{1};
    int v{1};
    std::cout << "h" << std::endl;
    std::cout << var << std::endl;
    server();
    return 0;
}
