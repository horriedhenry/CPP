#include <iostream>
#include <string>

class Student
{
private:
    std::string name;

public:
    float* cgpaPtr;
    Student(std::string&& name, float&& cgpa)
    {
        this->name = name;
        cgpaPtr = new float;
        *cgpaPtr = cgpa;
    }

    // deep copy
    Student(Student& orgObj)
    {
        this->name = orgObj.name;
        cgpaPtr = new float;
        *cgpaPtr = *orgObj.cgpaPtr;
    }

    void changeInfo(std::string&& name, float&& cgpa)
    {
        this->name = name;
        *cgpaPtr = cgpa;
    }

    void getInfo()
    {
        std::cout << this->name << "\n";
        std::cout << *cgpaPtr << "\n";
    }
};

int main (int argc, char *argv[])
{
    Student s1("henry", 7.5);
    s1.getInfo();

    Student s2(s1);
    *(s2.cgpaPtr) = 5;

    s1.getInfo();

    return 0;
}
