#include <iostream>
#include <vector>

void bubble_sort(std::vector<int>& arr) {
    int counter = arr.size() - 1;
    while (counter >= 0) {
        for (int i = 0; i < counter; i++) {
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
        counter--;
    }
}

int main (int argc, char *argv[]) {
    std::vector<int> arr = {9,8,7,6,5,4,3,2,1};
    bubble_sort(arr);
    for (auto it = arr.begin(); it != arr.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    return 0;
}
