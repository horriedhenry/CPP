#include <iostream>

class Counter {
public:
    // declared inside the class (once)
    static int counter;

    Counter()
    {
        // or just use counter
        Counter::counter++;
    }

    void displayCount()
    {
        // same here just use counter, it works
        std::cout << Counter::counter << '\n';
    }
};

// Static attribute must be defined/initialized outside the class.
// This is required by the compiler for proper linkage.
// int Counter::counter; // Just definition (value is zero-initialized by default)
int Counter::counter{0};  // Definition + explicit initialization to 0

int main()
{
    Counter cObj1;
    cObj1.displayCount(); // count : 1

    Counter cObj2;
    cObj2.displayCount(); // count : 2

    Counter cObj3;
    cObj3.displayCount(); // count : 3

    // std::cout << Counter::counter << '\n'; // prints 3

    // you can also access counter using an object as it's public
    // Regardless of which object is used, static members are shared across all instances
    // but it's recommend to use the class name

    std::cout << cObj1.counter << '\n';
}
