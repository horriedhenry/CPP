# std::vector

[cplusplus.com](https://cplusplus.com/reference/vector/vector/)


The `std::vector` class in C++ Standard Template Library (STL) is a dynamic array that can grow or shrink at runtime. It provides functionality for storing a collection of elements of the same type and offers efficient access and manipulation of those elements.

Key characteristics of `std::vector`:

- **Dynamic Size:** Unlike traditional arrays with a fixed size at compile time, `std::vector` can adjust its size automatically to accommodate adding or removing elements.

- **Random Access:** Elements within a vector can be accessed directly using their index (position) in constant time complexity (O(1)), similar to arrays.

- **Contiguous Storage:** Elements in a vector are stored in contiguous memory locations, allowing for efficient iteration and memory access.

- **Iterators:** `std::vector` provides iterators that act as pointers to elements within the vector, enabling traversal and manipulation of elements.

**Formal aspects:**

The `std::vector` class is typically defined within the `<vector>` header file. It offers various member functions for functionalities like:

- **Size Management:** `size()`, `capacity()`, `empty()`
- **Element Access:** `operator[]`, `at()`
- **Modifiers:** `push_back()`, `pop_back()`, `insert()`, `erase()`
- **Iterators:** `begin()`, `end()`, `rbegin()`, `rend()`

### Different ways to initialize, declare std::vector

```c++
#include <vector>

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
```
