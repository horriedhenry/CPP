#include <iostream>
#include <vector>

#define newline "\n"
#define endl std::endl

int main (int argc, char *argv[])
{
    // declare a vector named first
    std::vector<int> first;

    // creates a vector second with 10 integer elements, all initialized to 100.
    std::vector<int> second (10, 100);

    // creates a vector foo with list initialization
    std::vector<int> foo {1, 2, 3, 4, 5};

    // Creates a vector bar as a copy of elements from foo, iterating from beginning to end of foo.
    std::vector<int> bar (foo.begin(), foo.end());

    // Creates a vector baz as a copy of the entire vector 'foo'.
    std::vector<int> baz (foo);

    return 0;
}
