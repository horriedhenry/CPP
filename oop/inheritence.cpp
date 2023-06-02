#include <iostream>
#include <stdio.h>
using namespace std;
// source : [https://www.javatpoint.com/cpp-inheritance]
// # Single Level Inheritance

/*
NOTES Example 2(ChatGpt Response):
The code you provided demonstrates the concept of inheritance in C++. In this
case, class B is inheriting privately from class A using the private access
specifier.

When a class is inherited privately, the public and protected members of the
base class become private members of the derived class. However, the private
members of the base class are not accessible directly by the derived class.

In the given code, the private members a and b of class A cannot be accessed
directly by class B. However, class B can access the public member function
mul() of class A because it has been inherited privately.

The display_mul() function in class B invokes the mul() function from class A,
which returns the multiplication of a and b. The result is then displayed using
cout.

So, class B cannot directly access the private members
a and b of class A. It can only access them indirectly through the public member
functions of class A, such as mul().
*/
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

// Example 2
class A {
private:
    int a = 5,b = 4;
    void printAB() { cout << a << ","<<b<<endl; }
    // TODO :
    // create a method void printAB() { cout << a << " "<<b<<endl; }
    // and check where can it be used
public:
    int mul() {
        return a * b;
    }
    void access_Printab_classA() {
        // TODO solution
        printAB();
    }
};

class B : private A {
// When you use private access specifier , then all the public and protected
// members of class A become private members of class B , hence they can only 
// be accessed within the class i.e(B).
//
// ***Imp : The private members of class A cannot be inherited by B even When
// you use private access specifier , that means you cannot use the private
// attributes of class A in B (ex. we cannnot use a,b vars in this class even 
// privately.
// And as we know we cannot access private members with objects.
public:
    void display_mul() {
        cout<<"a * b = "<<mul()<<endl;
    }
    void access_Printab_WithClassB() {
        // TODO solution
        access_Printab_classA();
    }
};

int main (int argc, char *argv[]) {
    B b;
    b.display_mul();
    cout<<endl;
    cout<<"Values of a, b that are in class A = ";
    b.access_Printab_WithClassB();
    return 0;
}
