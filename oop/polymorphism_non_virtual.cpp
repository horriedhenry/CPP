#include <iostream>

class Animal {
public:
    void speak()
    {
        std::cout << "Animal speaks\n";
    }
};

class Dog : public Animal {
public:
    void speak() {
        std::cout << "Dog barks\n";
    }
};

class Cat : public Animal {
public:
    void speak() {
        std::cout << "Cat meows\n";
    }
};

int main ()
{
    Animal* animal;
    Dog dog;
    Cat cat;

    animal = &dog;
    animal->speak(); // prints : dog barks

    animal = &cat;
    animal->speak(); // prints : cat meows

    Dog dog2;
    dog2.speak();
}
