#include <iostream>

class MyObj {
public:
    MyObj()
    {
        std::cout << "MyObj Constructor called\n";
    }

    void doSomething()
    {
        std::cout << "MyObj is doing something\n";
    }

    ~MyObj()
    {
        std::cout << "MyObj Destructor called\n";
    }
};

void functionWithStaticObject()
{
    std::cout << "Entering functionWithStaticObject\n";
    static MyObj obj;
    std::cout << "Exiting functionWithStaticObject\n\n";
}

void functionWithNonStaticObject()
{
    std::cout << "Entering functionWithNonStaticObject\n";
    MyObj obj;
    std::cout << "Exiting functionWithNonStaticObject\n";
}

int main()
{
    std::cout << "Entering main() \n";

    functionWithStaticObject();
    std::cout << '\n';
    functionWithStaticObject();
    std::cout << '\n';
    functionWithStaticObject();

    // functionWithNonStaticObject
    functionWithNonStaticObject();
    std::cout << '\n';
    functionWithNonStaticObject();
    std::cout << '\n';

    std::cout << "Exiting main() \n";
    return 0;
}
