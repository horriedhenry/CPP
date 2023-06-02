#include <iostream>
#include <stdio.h>
using namespace std;
// source : [https://www.javatpoint.com/cpp-inheritance]
// # Single Level Inheritance

class Animal {
// Base Class
public:
    std::string Type = "Animal";
    void eat() {
        cout<<"Eating..."<<endl;
    }
    void see() {
        cout<<"Watching.."<<endl;
    }
};

// Single level Inheritance
class Dog : public Animal {
// Derived class -> inheriting from class Animal
// Dog class now has access to all the public methods, and class members
// or attributes
public:
    int age;
    void bark() {
        cout<<"Dog Barks"<<endl;
    }
    void type() {
        cout<<Type<<endl;
    }
};

int main (int argc, char *argv[]) {
    Dog d;
    d.eat();
    d.see();
    d.bark();
    d.type();
    return 0;
}
