#include <array>
#include <iostream>
#include <vector>
/*

v.front() - print 1st element
v.back() - print 2nd element
begin() - return pointer pointing to 1st element in vector.
end() - return pointer pointing to 2nd element in vector.

*/

void basic_stuff() {
    std::vector<int> v;
    v.push_back(5);
    v.push_back(2);
    v.pop_back();
    // can also access elements using v[index]
    // iterate through a vector
    // for (auto it=v.begin(); it!=v.end(); ++it) {
    //     std::cout << *it << " ";
    // }
    // or declare an iterator
    std::vector<int>::iterator it;
    for(it = v.begin(); it!=v.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    for(auto element : v) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
    // vector of strings
    std::vector<std::string> vs;
    vs.push_back("horried");
    vs.push_back("henry");
    for (auto it=vs.begin(); it!=vs.end(); ++it) {
        std::cout << it->capacity() << " ";
    }
    std::cout << std::endl;
    std::cout << "v.at(0) => " << v.at(0) << std::endl;
}

void vector_of_arrays() {
    // cannot use c-style arrays to create a vector_of_arrays
    // int arr_[3] = {1, 2, 3};
    // int arr_1[3] = {4, 5, 6};
    //
    // vector of arrays each array is of size 3
    std::vector<std::array<int, 3>> va;
    std::array<int, 3> arr1 = {1, 2, 3};
    std::array<int, 3> arr2 = {4, 5, 6};
    // int size = arr1.size();
    // std::cout << "arr.back() = " << arr1.back() << "\n";
    va.push_back(arr1);
    va.push_back(arr2);
    std::vector<std::array<int,3>>::iterator it;
    for(it = va.begin(); it!=va.end(); ++it) {
        // std::array<int,3>::iterator ait; can also use this
        // should specify size of array , better just to use auto
        for(auto ait = it->begin(); ait!=it->end(); ait++) {
            std::cout << *ait << " ";
        }
        std::cout << std::endl;
    }
    // also taking input is similar , just add "cin" in inner loop
}

void vector_2d_arrays() {
    // TODO : Implement vector_2d_arrays.
}

void vector_assign() {
    std::vector<int> first;
    std::vector<int> second;
    std::vector<int> third;
    first.assign(5, 100); // create a vector of int's with value 100, i.e it is
    // a vector of 5 ints with a value of 100.
    int size_of_array = 3;
    int arr[] = {1,2,3};
    second.assign(arr, arr + size_of_array);
    for (auto it = second.begin(); it != second.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";
    int arr2[size_of_array];
    // for (int e : arr2) {
    //     std::cin >> e;
    // } cannot use a range based loop to take input.
    for(int i = 0; i < size_of_array; i++) {
        std::cin >> arr2[i];
    }
    third.assign(arr2, arr2 + size_of_array);
    for (auto it = third.begin(); it != third.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int main (int argc, char *argv[]) {
    vector_assign();
    return 0;
}
