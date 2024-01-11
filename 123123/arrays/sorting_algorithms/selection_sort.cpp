#include <iostream>
#include <vector>

// Find the minimum element in the unsorted array and swap it with the element
// in the beginning

// void selection_sort(std::vector<int>& arr) {
//     int size = arr.size();
//     for (int i = 0; i < size; i++) {
//         int min_ele_index = i;
//         for (int j = i + 1; j < size; j++) {
//             if (arr[j] < arr[min_ele_index]) {
//                 min_ele_index = j;
//             }
//         }
//         int temp = arr[i];
//         arr[i] = arr[min_ele_index];
//         arr[min_ele_index] = temp;
//     }
// }

void selection_sort(std::vector<int>& arr) {
    int size = arr.size();
    for (int i = 0; i < size; i++) {
        int min_ele_index = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min_ele_index]) {
                min_ele_index = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min_ele_index];
        arr[min_ele_index] = temp;
    }
}

int main (int argc, char *argv[]) {
    std::vector<int> arr = {8,5,2,6,9,3,1,4,0,7};
    selection_sort(arr);
    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
