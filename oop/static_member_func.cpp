#include <iostream>

class MathOperations {
public:
    int number;
    static int add(int a, int b) { 
        // return number + a + b; // throws an error : 
        // Invalid use of member 'number' in static member function [invalid_member_use_in_method]
        // cannot use non-static members inside static methods
        return a + b;
    }
    static int multiply(int a, int b) {
        return a * b;
    }
};

int main() {
    std::cout << "Sum: "     << MathOperations::add(5, 3)      << '\n';
    std::cout << "Product: " << MathOperations::multiply(4, 2) << '\n';
    
    // can also use an object
    MathOperations obj;
    std::cout << "Sum: "     << obj.add(4, 5) << '\n';
    return 0;
}
