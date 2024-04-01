#include <iostream>

void print()
{
    std::cout << "hi" << "\n";
}

int ret()
{
    return 5;
}

int main (int argc, char *argv[])
{
    print();
    ret();
    // std::cout << print() << "\n";
    // or similarly
    // std::string temp { print() }; // temp requires a value
    return 0;
}
