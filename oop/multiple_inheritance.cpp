#include <iostream>

class Student
{
public:
    std::string name;
    int rollNo;

    Student(const std::string name, const int rollNo)
    {
        this->name = name;
        this->rollNo = rollNo;
    }
};

class Teacher
{
public:
    std::string subject;
    double salary;

    Teacher(const std::string subject, const int salary)
    {
        this->subject = subject;
        this->salary = salary;
    }
};

class TeachingAssistant : public Student, public Teacher
{
public:
    std::string researchArea;

    TeachingAssistant(const std::string name, const int rollNo, const std::string subject, const int salary, const std::string researchArea) : Student(name, rollNo) , Teacher(subject, salary)
    {
        this->researchArea = researchArea;
    }

    void getInfo()
    {
        std::cout << this->name << "\n";
        std::cout << this->rollNo << "\n";
        std::cout << this->subject << "\n";
        std::cout << this->salary << "\n";
        std::cout << this->researchArea << "\n";
    }
};

int main (int argc, char *argv[])
{
    TeachingAssistant t("henry", 21, "physics", 30000, "biology");
    t.getInfo();
    return 0;
}
