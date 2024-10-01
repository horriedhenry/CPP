#include <iostream>
#include <string>

class GymMember
{
private:
    int age;
    std::string name;
    std::string guide_name;
    double weight;
    double fee;
public:
    // non-parameterized constructor
    GymMember()
    {
        std::cout << "member added \n";
    }

    // parameterized constructor
    GymMember(std::string name_, int age_, double weight_,
              std::string guide_name_, double fee_) {
        name = name_;
        age = age_;
        weight = weight_;
        guide_name = guide_name_;
        fee = fee_;
    }

    // setter - if no constructor is used
    void setMemberDetails(std::string&& name_, int&& age_, double&& weight_,
              std::string&& guide_name_, double&& fee_) {
        name = name_;
        age = age_;
        weight = weight_;
        guide_name = guide_name_;
        fee = fee_;
    }

    // getter
    void printMemberDetails() {
      std::cout << "Name        : " << name << "\n";
      std::cout << "Age         : " << age << "\n";
      std::cout << "Weight      : " << weight << "\n";
      std::cout << "Guide Name  : " << guide_name << "\n";
      std::cout << "Fee         : " << fee << "\n";
    }
};

int main (int argc, char *argv[])
{
    // GymMember New; // will print member added as we did not provide any argument
    // New.setMemberDetails("henry", 22, 52.5, "someone", 1000);
    // New.printMemberDetails();

    GymMember New("henry", 22, 52.5, "someone", 1000); // the compiler will know what constructor to call.
    New.printMemberDetails();

    return 0;
}
