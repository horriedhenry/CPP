#include <iostream>
#include <string>

#define endl std::endl

class Person {
std::string name; // private by default
int age;
std::string address;
public:
    void setter(std::string&& name, int&& age, std::string&& address) {
        this->name = name;
        this->age = age;
        this->address = address;
    }

    void getter_all() {
        std::cout << name << endl;
        std::cout << age << endl;
        std::cout << address << endl;
    }

    std::string& get_name() {
        // getter with a return value(can be any type)
        return name;
    }
    int& get_age() {
        return age;
    }
    std::string& get_address() {
        // getter with a return value(can be any type)
        return address;
    }
};

int main (int argc, char *argv[]) {
    Person a;
    a.setter("henry", 21, "neekendhuku");
    int& age = a.get_age();
    std::string& name = a.get_name();
    std::string& address = a.get_address();
    std::cout << name << endl;
    std::cout << age << endl;
    std::cout << address << endl;

    //
    Person other;
    other.setter("other", 0, "djkdjfkjdjfkjd");
    other.getter_all();
    return 0;
}
