#include <iostream>

class Student
{
private:
    std::string name;
    float cgpa;

public:
    Student(std::string&& name, float&& cgpa)
    {
        this->name = name;
        this->cgpa = cgpa;
    }

    // copy constructor (shallow)
    Student(Student& orgObj)
    {
        this->name = orgObj.name;
        this->cgpa = orgObj.cgpa;
    }

    void changeInfo(std::string&& name, float&& cgpa)
    {
        this->name = name;
        this->cgpa = cgpa;
    }

    void getInfo()
    {
        std::cout << this->name << "\n";
        std::cout << this->cgpa << "\n";
    }
};

int main (int argc, char *argv[])
{
    Student s1("henry", 7.5);
    s1.getInfo();

    Student s2(s1);
    s2.getInfo();

    s2.changeInfo("someone", 5.0);
    s2.getInfo();
    return 0;
}
