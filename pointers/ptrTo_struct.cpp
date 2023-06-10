#include <iostream>
#include <stdio.h>
#include <string>

typedef struct House {
    std::string location;
    int sqFoot;
    int noOfBedrooms;
}House;

void PrintHouseLocation(House param) {
    // Pass by value i.e a copy of the struct will be made.
    // This can be expensive because this function will make a copy of the house
    // struct to print the location. If the struct is of large size this can
    // be an expensive operation.
    std::cout<<param.location<<"\n";
}

void PrintHouseLocation(House* param) {
    // Pass by reference i.e using address of struct to access it's members.
    // This function will take the address of the house struct to print the location.
    // It is not an expensive operation.
    std::cout<<param->location<<"\n";
}

int main (int argc, char *argv[]) {
    House house = {"Dholakpur", 300, 6};
    House* housePtr = &house;
    std::cout<<"Using house object directly (.) : "<<"\n";
    std::cout<<house.location<<std::endl;
    std::cout<<house.sqFoot<<std::endl;
    std::cout<<house.noOfBedrooms<<std::endl;
    std::cout<<"Using pointer to structure (->) :"<<"\n";
    std::cout<<housePtr->location<<std::endl;
    std::cout<<housePtr->sqFoot<<std::endl;
    std::cout<<housePtr->noOfBedrooms<<std::endl;
    std::cout<<"Print house location by passing a copy of struct PrintHouseLocation(House Param)"<<"\n";
    PrintHouseLocation(house);
    std::cout<<"Print house location by passing a copy of struct PrintHouseLocation(House* param)"<<"\n";
    PrintHouseLocation(&house);
    housePtr++;
    housePtr->location = "location";
}
