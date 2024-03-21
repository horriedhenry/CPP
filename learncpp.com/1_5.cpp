#include <iostream>
#include <chrono>
#include <thread>

int main()
{
    std::cout << "This will stay in the buffer ";

    // The statement above will not be displayed in the console until a newline character or std::endl is encountered.
    // we can conform this by adding a delay before printing the next statement.
    // This program will wait for 5 seconds and prints both statements at once i.e it flushes the buffer and prints everyting
    // in it until that point.

    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cout << "Until a newline or flush is encountered." << std::endl;
    int a{};
    std::cin >> a;

    return 0;
}
