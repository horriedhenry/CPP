#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    std::string name;
    float Gpa;
    int age;

public:
    // public attribues can be accessed where ever the object is accessed
    std::string insta_id;
    // setter
    void setAll(std::string name, int age, float Gpa) {
        // read comments on getAll() , it's the same here too set one or all
        // you cal also make some attribues of this class public
        this->name = name;
        this->age = age;
        this->Gpa = Gpa;
    }
    // getter
    void getAll() {
        // You also can just return one member or every attribute using getter
        // you get the idea
        cout<<this->name<<endl;
        cout<<this->age<<endl; 
        cout<<this->Gpa<<endl;
    }
    // getter with return value, (Just me trying stupid stuff)
    Student getter(Student& stud) {
        return stud;
    }
};

int main (int argc, char *argv[]) {
    Student Tim;
    Tim.setAll("Tim", 21, 9.8);
    Tim.insta_id = "fuckoff@fucku";
    Student TempRef = Tim.getter(Tim);
    TempRef.getAll();

    // You can do a lot of stuff(stupid stuff like below which i guess is so
    // expensive in case of memory)
    // If the attribues of the class are public then it is ok, it 
    // Will not be that many lines of code like for private attribues 
    // We can just use this cin>>students[i].insta_id;
    Student students[2];
    std::string name;
    int age;
    float Gpa;
    for(int i=0; i < 2; i++) {
        cin>>name;
        cin>>age;
        cin>>Gpa;
        students[i].setAll(name, age, Gpa);
        students[i].getAll();
    }
    return 0;
}
