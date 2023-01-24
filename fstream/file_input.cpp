// read from a file
#include <fstream>
#include <iostream>
using namespace std;

int main (int argc, char *argv[])
{
    ifstream file {"file.txt"};
    if(!file) {
        cout<<"cannot open file";
        return 1;
    }
    while(file) {// while there is content in file loop
        // read a line from a file and store it in string
        string strInput;
        file >> strInput;
        cout<< strInput << endl;
    }
    return 0;
}
