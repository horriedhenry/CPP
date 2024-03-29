#include <iostream>

int main (int argc, char *argv[])
{
    // As we know cout is buffered..
    // and until the compiler encounters a new line or std::endl or the buffer reaches a certain size the buffer will not be flushed, but we can explicitly flush the buffer by using....
    std::cout << 
        "Ther is no new line here in this statement but use std::cout.flush() to explicitly flush the buffer" 
        << std::flush;
    // or
    std::cout << 
        "Ther is no new line here in this statement but use std::cout.flush() to explicitly flush the buffer \n";
    std::cout.flush();

    // Ternary operator

    int age { 18 };
    bool isAdult { (age >= 18) ? true : false };

    std::string out { (isAdult) ? "Is an Adult" : "Not an Adult" };
    std::cout << out << "\n";
    return 0;
}
