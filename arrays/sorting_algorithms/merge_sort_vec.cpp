#include <iostream>
#include <vector>

void merge(std::vector<int>& arr, int left, int mid, int right) {
    int i = left, j = mid + 1;
    std::vector<int> temp;
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
        }
    }
    while (i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }
    while (j <= right) {
        temp.push_back(arr[j]);
        j++;
    }
    for (int k = 0; k < temp.size(); k++) {
        arr[left + k] = temp[k];
    }
}

void merge_sort(std::vector<int>& arr, int left, int right) {
    // DONE
    // for (int i = left; i <= right; i++) {
    //     std::cout << arr[i] << " ";
    // }
    // std::cout << std::endl;
    if (left < right) {
        int mid = (left + right) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr,left,mid,right);
    }
}

int main (int argc, char *argv[]) {
    std::vector<int> arr = {2,8,5,3,9,4,1,7};
    // std::vector<int> arr = {5,4,3,2,1};
    merge_sort(arr, 0, arr.size() - 1);
    // Print elements after sorting
    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
