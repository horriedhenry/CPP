#include <iostream>
#include <vector>

int partition(std::vector<int>& arr, int low, int high)
{
    int pivot = arr[high];
    int idx = low - 1;

    int i;
    for (i = low; i < high; i++) {
        if (arr[i] <= pivot) {
            idx++;
            int temp = arr[i];
            arr[i] = arr[idx];
            arr[idx] = temp;
        }
    }

    idx++;
    arr[high] = arr[idx];
    arr[idx] = pivot;
    return idx;
}

void quick_sort(std::vector<int>& arr, int low, int high) {
    if (low >= high) {
        // used <= did not work
        return;
    }

    int pivot = partition(arr, low, high);

    quick_sort(arr, low, pivot - 1);
    quick_sort(arr, pivot + 1, high);
}

int main (int argc, char *argv[])
{
    std::vector<int> arr {9,6,2,1,4,5};
    quick_sort(arr, 0, arr.size() - 1);
    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    std::cout << arr.size() << std::endl;
    return 0;
}
