#include <iostream>
#include <string>

#define endl std::endl

class Student {
std::string name; // private by default
int age;
std::string address;
public:
    // default constructor
    Student() : name("default"), age(0) {}
    // Student() {
    //     // default constructor is used when no parameters are passed
    //     // ex Student s;
    //     // s will call this when declared
    //     this->name = "default";
    //     this->age = 0;
    // }

    Student(const std::string& name, const int& age, const std::string& address) {
        this->name = name;
        this->age = age;
        this->address = address;
    } // parameterized constructor

    void getter() {
        std::cout << this->name << endl;
        std::cout << this->age << endl;
    }

    void setter(const std::string& name, const int& age, const std::string& address) {
        this->name = name;
        this->age = age;
    }

    // copy constructor (deep copy not default).
    Student(const Student& copy_from_to_current_obj) {
        this->name = copy_from_to_current_obj.name;
        this->age = copy_from_to_current_obj.age;
        this->address = copy_from_to_current_obj.address;
    }
    ~Student();
};

int main (int argc, char *argv[]) {
    Student* s1 = new Student("henry", 21, "address");
    s1->getter();
    delete s1;
    Student s2("s2", 22, "s2address");
    Student s3 = s2; // copy constructor will be called (deep copy)
    s3.getter();
    return 0;
}
