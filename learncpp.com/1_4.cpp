#include <iostream>
#include <string>

#define endl "\n"

int return_int()
{
    return 100;
}

int func(int a)
{
    std::cout << "a from func() : " << a << endl;
    return a;
}

int main (int argc, char *argv[])
{
    // value initialization
    int a{}; // default value is 0
    std::cout << "a : " << a << endl;

    int value_init{}; // default value is 0
    std::cout << "value_init : " << value_init << endl;


    int c(1);
    std::cout << "c : " << c << endl;

    int d(return_int());
    std::cout << "d : " << d << endl;

    // Direct List Initialization

    int b{return_int()}; // Direct List init
    std::cout << "b : " << b << endl;

    std::string name{"Henry"}; // Direct List Initialization

    // prefer list initialization (reason)

    float float_number = 1.222;
    int int_number = float_number; // this does not throw any error, it just converts float to int
    // the developer might not want this, should throw an error to indicate that one is doing type conversion

    std::cout << "float number : " << float_number << endl;
    std::cout << "int number : " << int_number << endl;

    // but
    float float_nbr{1.22};
    // this throws an error
    // int int_nbr{float_nbr}; // float cannot be narrowed to int in initilazer list
    // solve this by using type conversion to int
    int int_nbr{int(float_nbr)}; // when some dev does this he know that he is doing type conversion.

    // Initialize your variables upon creation.
    int i; // this is bad, we dont even know if we would use this
    //...
    i = 7; // check : (https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#es20-always-initialize-an-object)
    return 0;
}
