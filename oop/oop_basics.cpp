#include <iostream>
#include <string>

#define endl std::endl

class Person {
// all member variables and functions are private by default.
public:
    std::string name; // variable
    int age; // variable

    void print_person_data() {
        // a private member function can only be used inside the class (an object declared from this class cannot use a private member function or variables)
        Print_person_data();
    }
    void set_address(std::string&& add) {
        // setter
        address = add;
    }
    std::string get_address() {
        // getter
        return address;
    }
    void print_address() {
        std::cout << address << endl;
    }
private:
    std::string address;
    void Print_person_data() {
        std::cout << name << endl;
        std::cout << age << endl;
    }
};

int main (int argc, char *argv[]) {
    Person henry;
    henry.name = "Henry";
    henry.age = 21;
    henry.print_person_data();
    henry.set_address("an address");
    std::string address = henry.get_address();
    std::cout << address << endl;
    return 0;
}
