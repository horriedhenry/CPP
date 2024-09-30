#include <iostream>
#include <string>

class Teacher
{
private:
    double salary;

public:
    std::string name;
    std::string department;
    std::string subject;
    // methods or member functions
    void changeDepartment(std::string& dep)
    {
        department = dep;
    }

    // setter - set value for a private atrribute
    void setSalary(double s)
    {
        salary = s;
    }

    // getter - get value of a private attribute
    double getSalary()
    {
        return salary;
    }
};

int main (int argc, char *argv[])
{
    Teacher t;
    t.name = "teacher";
    t.department = "CSE";
    t.subject = "Physics";

    t.setSalary(50000);
    double salary { t.getSalary() };
    std::cout << salary << "\n";
    return 0;
}
