#include <iostream>
#include <stdlib.h>

typedef struct House {
    std::string location;
    int sqFoot;
    int noOfBedrooms;
}House;

void* MyAlloc(size_t param) {
    return malloc(sizeof(param));
}

int main (int argc, char *argv[]) {
    int num = 112;
    void* numPtr = &num;
    std::cout<<*((int *)numPtr);
    House* pHouse = nullptr;
    pHouse = (House *)MyAlloc(sizeof(House));
    // give the same result
    House* PHouse = nullptr;
    PHouse = (House *)malloc(sizeof(House));
    pHouse->location = "fucking location";
    PHouse->location = "fucking location PHouse";
    std::cout<<pHouse->location<<std::endl;
    std::cout<<PHouse->location<<std::endl;
    free(pHouse);
    pHouse = nullptr;
    free(PHouse);
    PHouse = nullptr;
    return 0;
}
