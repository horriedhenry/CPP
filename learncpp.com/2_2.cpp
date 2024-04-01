#include <iostream>

int returnFive()
{
    return 5;
}

int main()
{
    std::cout << returnFive << '\n'; // this apparently prints 1
    return 0;
}
