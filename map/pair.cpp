#include <iostream>
#include <string>
#include <utility>

#define endl std::endl

/* 

init :

std::pair<data_type1, dt2> pair_name;

init2 :

std::pair<data_type1, dt2> pair_name(value1_of data_type1, v2 of d2);

init 3 : 

pair<dt1,dt2> pair_name;
pair_name = make_pair(vdt1, vdt2); // value1_of data_type1..

init4 : 

pair<dt1,dt2> pair_name;
pair_name = {vdt1, vdt2};

*/

int main (int argc, char *argv[]) {
    std::pair<char, int> p;
    p.first = 'a';
    p.second = 1;
    // access
    std::cout << "p1" << endl;
    std::cout << p.first << endl;
    std::cout << p.second << endl;
    // init2
    std::string name = "henry";
    int age = 21;
    std::pair<std::string, int> p2(name, age);
    std::cout << "p2" << endl;
    std::cout << p2.first << endl;
    std::cout << p2.second << endl;
    // other way of initializing a pair.
    std::pair<int,int> p3;
    p3 = std::make_pair(1,2);
    std::cout << "p3" << endl;
    std::cout << p3.first << endl;
    std::cout << p3.second << endl;
    // another way of initializing pair.
    std::cout << "p4" << endl;
    std::pair<int,int> p4;
    p4 = {22,22};
    std::cout << p4.first << endl;
    std::cout << p4.second << endl;
    return 0;
}
