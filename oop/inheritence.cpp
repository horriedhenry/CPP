#include <iostream>
#include <stdio.h>
using namespace std;
// source : [https://www.javatpoint.com/cpp-inheritance]
// # Multi-Level Inheritance

/*
NOTES :
*/
class Animal {
// Base Class
public:
    std::string AnimalType = "Animal";
    void eat() {
        cout<<"Eating..."<<endl;
    }
    void see() {
        cout<<"Watching.."<<endl;
    }
};

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
        cout<<AnimalType<<endl;
    }
};

// Multi-Level Inheritance
// -> When a class inherits from one class which is further inherited by other
// class. ex : A,B,C are the classes then B inherits from A, and C inherits B 
// which inherits A
class BabyDog : public Dog {
public:
    void weep() {
        cout<<"BabyDog Weeping..."<<endl;
    }
    void crawl() {
        cout<<"BabyDogcrawling"<<endl;
    }
    void bark() {
        cout<<"BabyDog Barks"<<endl;
        Dog::bark();
    }
};

int main (int argc, char *argv[]) {
    BabyDog baby;
    baby.weep();
    baby.crawl();
    baby.bark();
    baby.Dog::bark(); // `::` -> scope resolution operator
    // `::` -> used to specify which version of function to be used
    return 0;
}
