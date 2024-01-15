#include <iostream>
#include <vector>

int bin_search(std::vector<int> arr, int key) {
    int left = 0, right = arr.size();
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == key) {
            return mid;
        } else if (key > arr[mid]) {
            left = mid + 1;
        } else if (key < arr[mid]){
            right = mid - 1;
        }
    }
    return -1;
}

int bin_search_rec(std::vector<int> arr, int left, int right, int key) {
    if (left > right) {
        return - 1;
    }
    int mid = (left + right) / 2;
    // int mid = left + right / 2;
    // doc this if i don't use (left + right) / 2 returns - 1 , if used works fine.
    if (arr[mid] == key) {
        return mid;
    } else if (key > arr[mid]) {
        return bin_search_rec(arr, mid + 1, right, key);
    } else if (key < arr[mid]){
        return bin_search_rec(arr, left, mid - 1, key);
    }
    return -1;
}


int main (int argc, char *argv[]) {
    std::vector<int> arr = {1,2,3,4,5};
    // std::cout << bin_search_rec(arr, 0, arr.size(),5) << std::endl;
    std::cout << bin_search(arr, 6) << std::endl;
    return 0;
}
