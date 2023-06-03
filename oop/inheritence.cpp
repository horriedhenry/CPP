#include <iostream>
using namespace std;
// source : [https://www.javatpoint.com/cpp-inheritance]
// # Multiple Inheritance.
// # Ambiquity Resolution in Inheritance



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
    void ambiguity() {
        cout<<"Ambiquity .. Vehicle class"<<endl;
    }
};

// Base class 1
class MusicPlayer {
public:
    void play_music() {
        std::cout<<"Playing music$$"<<endl;
    }
    void ambiguity() {
        cout<<"Ambiquity .. MusicPlayer class"<<endl;
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
    void viewAmbiquity() {
        Vehile::ambiguity();
        MusicPlayer::ambiguity();
    }
};

int main (int argc, char *argv[]) {
    Car car;
    //car.ambiguity();//gives an error coz ambiguity exists in two base classes
    // We should use Vehile::ambiguity(); to specify from which base class
    // should we use the function from.
    car.viewAmbiquity();
    return 0;
}
