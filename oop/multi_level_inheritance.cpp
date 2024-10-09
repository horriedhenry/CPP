#include <iostream>

class Person 
{
private:
    int salary;

public:
    std::string name;
    int age;

    Person(std::string name, int age)
    {
        this->name = name;
        this->age = age;
    }

    void getInfo()
    {
        std::cout << this->name << "\n";
        std::cout << this->age << "\n";
    }
};

class Student : public Person
{
private:
    int rollNo;

public:
    Student(std::string name, int age, int rollNo) : Person(name, age)
    {
        this->rollNo = rollNo;
    }

    void getInfo()
    {
        Person::getInfo();
        std::cout << this->rollNo << "\n";
    }
};

class GraduatedStudent : public Student
{
private:
    double cgpa;

public:
    GraduatedStudent(std::string name, int age, int rollNo, double cgpa) : Student(name, age, rollNo)
    {
        this->cgpa = cgpa;
    }

    void getInfo()
    {
        Student::getInfo();
        std::cout << this->cgpa << "\n";
    }
};

int main (int argc, char *argv[])
{
    // std::string name = "henry";
    // int age = 12;
    // int rollNo = 33;

    GraduatedStudent s("henry", 25, 444, 7.7);

    // s.Person::getInfo();
    // s.Student::Person::getInfo();

    s.getInfo();
    return 0;
}
