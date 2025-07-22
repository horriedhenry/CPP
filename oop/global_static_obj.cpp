#include <iostream>

class MyGlobalClass {
public:
    MyGlobalClass() { std::cout << "Global constructor!\n"; }
    void doSomething()
    {
        std::cout << "Doing Something!\n";
    }
    ~MyGlobalClass() { std::cout << "Global destructor!\n"; }
};

MyGlobalClass globalObj;

void fun();

int main ()
{
    std::cout << "Inside main()\n";
    fun();
    std::cout << "Exit main()\n";
    return 0;
}

void fun()
{
    std::cout << "Inside fun()\n";
    globalObj.doSomething();
}
