#include <iostream>

class Person
{
public:
    std::string name;
    int age;

    Person(std::string name, int age)
    {
        this->name = name;
        this->age = age;
    }
};

class Student : public Person
{
public:
    int rollno;

    Student(std::string name, int age, int rollno) : Person(name, age)
    {
        this->rollno = rollno;
    }

    void getInfo()
    {
        std::cout << this->name << "\n";
        std::cout << this->age << "\n";
        std::cout << this->rollno << "\n";
    }
};

int main (int argc, char *argv[])
{
    Student s("henry", 21, 69);
    s.getInfo();
    return 0;
}
