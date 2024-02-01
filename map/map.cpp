#include <iostream>
#include <map>
#include <utility>

// map is similar to a dictionary(but it's not)
// map has key, value pairs

#define endl std::endl

int main (int argc, char *argv[]) {
    std::map<char, int> m = {
        {'a', 1}, // this is a pair {'a', 1} - pair
        {'b', 2},
        {'c', 3},
    };
    // access element associated with a key.
    std::cout << m['a'] << endl; // out : 1
    // insert a pair to m
    m['d'] = 4;
    std::cout << m['d'] << endl; // out : 4
    // use std::pair<type_t, type_t> using insert method/func
    m.insert(std::pair<char,int>('e', 5));
    std::cout << m['e'] << endl; // out : 5
    // or declare a pair and then insert that
    std::pair<char,int> pf('f', 6);
    m.insert(pf);
    // access values of a pair using pair.first and pair.second
    std::cout << pf.first << endl; // out : f
    std::cout << pf.second << endl; // out : 6
    // delete a pair using erase()
    // m.erase('f'); // or
    m.erase(pf.first);
    // std::cout << m['f'] << endl; // out : 0 (just erased('f'))
    // iterate through a map
    std::cout << "iterate" << endl;
    for (std::map<char, int>::iterator it = m.begin(); it != m.end(); ++it) {
        std::cout << it->first << endl;
    }
    return 0;
}
