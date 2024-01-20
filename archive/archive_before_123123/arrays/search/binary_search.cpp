#include <iostream>
#include <vector>

int binary_search(std::vector<int>& arr, int key) {
    int size = arr.size();
    int left = 0, right = size - 1;
    while(left <= right) {
        int mid = left + right / 2;
        if(arr[mid] == key) {
            return mid;
        } else if (arr[mid] > key) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

int main (int argc, char *argv[]) {
    std::vector<int> arr = {1,2,3,4,5,6};
    int key = -1;
    int result = binary_search(arr, key);
    if(result == -1) {
        std::cout << "Not Found" << std::endl;
    } else {
        std::cout << "Fount at pos : " << result  << std::endl;
    }
    return 0;
}
