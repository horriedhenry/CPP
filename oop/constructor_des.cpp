#include <iostream>
#include <string>

#define endl std::endl

class Student {
std::string name; // private by default
int age;
public:
    // default constructor
    Student() {
        // default constructor is used when no parameters are passed
        // ex Student s;
        // s will call this when declared
        this->name = "default";
        this->age = 0;
    }

    Student(std::string&& name, int&& age, std::string&& address) {
        this->name = name;
        this->age = age;
    } // parameterized constructor

};

int main (int argc, char *argv[]) {
    return 0;
}
