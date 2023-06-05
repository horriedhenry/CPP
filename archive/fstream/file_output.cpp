// write to a file
#include <iostream>
#include <fstream>

int main (int argc, char *argv[])
{
    // ofstream is used to write to a file
    std::ofstream file {"file.txt"};
    if(!file) { // if we couldn't open a file 
        // print a message and exit
        std::cout<<"file not found";
        return 1;
    }
    // write contencts into file.txt
    file << "line 1\n";
    file << "line 2\n";
    file << "line 3";
    return 0;
}
