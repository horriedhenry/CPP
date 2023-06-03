#include <iostream>
using namespace std;
// source : [https://www.javatpoint.com/cpp-inheritance]
// # Multiple Inheritance.

/*
NOTES :
Multiple inheritance is the process of deriving a new class that inherits the 
attributes from two or more classes.
*/

// Base class 1
class Vehile {
public:
    int noOfWheels;
    void drive(std::string&& vehicle) {
        std::cout<<vehicle<<"is driving..."<<endl;
    }
};

// Base class 1
class MusicPlayer {
public:
    void play_music() {
        std::cout<<"Playing music$$"<<endl;
    }
};

class Car : public Vehile, public MusicPlayer{
public:
    void honk() {
        std::cout<<"honk honk..."<<endl;
    }
    void setWheels(int&& noOfWheels) {
        this->noOfWheels = 4;
    }
};

int main (int argc, char *argv[]) {
    Car car;
    car.drive("Car");
    car.play_music();
    car.honk();
    car.setWheels(4);
    cout<<car.noOfWheels<<endl;
    return 0;
}
