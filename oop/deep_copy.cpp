#include <iostream>
#include <string>

class Student
{
private:
    std::string name;

public:
    float* cgpaPtr;

    // default constructor if no arguments are passed when creating an object
    Student()
    {
        this->name = "student";
        cgpaPtr = new float;
        *cgpaPtr = 0;
    }

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

    // Destructor, called automatically
    ~Student()
    {
        std::cout << this->name <<" : delete cgpaPtr\n";
        delete cgpaPtr;
    }
};

int main (int argc, char *argv[])
{
    Student s1("henry", 7.5);

    Student s2(s1);
    s2.changeInfo("other", 10);
    *(s2.cgpaPtr) = 5;

    // s1.~Student();
    // s2.~Student();

    Student* s3 = new Student();
    // s3->~Student();
    delete s3;

    return 0;
}
