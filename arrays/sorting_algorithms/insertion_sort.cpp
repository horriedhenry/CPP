#include <iostream>
#include <vector>
#include <algorithm>

void insertion_sort(std::vector<int>& arr) {
    int size = arr.size();
    for (int i = 1; i < size; i++) {
        // if (arr[i] < arr[i - 1]) {
        //     while (arr[i] < arr[i - 1]) {
        //         std::swap(arr[i], arr[i - 1]);
        //         i--; // did not add i-- in the first run
        //     }
        // }
        while (arr[i] < arr[i - 1]) {
            // the current element should be greate than the previous element
            // then and only then we know that it is in the correct order in 
            // the array.
            std::swap(arr[i], arr[i - 1]);
            i--; // did not add i-- in the first run
        } // also works if we do not check arr[i], arr[i - 1]
    }
}

int main (int argc, char *argv[]) {
    // std::vector<int> arr = {2,8,5,3,9,4};
    std::vector<int> arr = {9,8,7,6,5,4,3,2,1,10};
    insertion_sort(arr);
    // std::sort(arr.begin(), arr.end());
    for (auto it = arr.begin(); it != arr.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    return 0;
}
