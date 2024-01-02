#include <climits>
#include <iostream>

int sum_array(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

int largest_element(int arr[], int size) {
    int large = INT_MIN;
    for (int i = 0; i < size; i++) {
        if(arr[i] > large) {
            large = arr[i];
        }
    }
    return large;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void print_reverser_order(int arr[], int size) {
    for (int i = size - 1; i >= 0; i--) {
        std::cout << arr[i] << " ";
    }
}

void reverse_array(int arr[], int size) {
    /*
    for (int i = 0; i < size; i++) {
        int temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
    does not reverse the array . But it does at some point in the loop, but then
    just goes to the beginning state .
    ex : 1 2 3 4 5 gives
         1 2 3 4 5
    that's why should use size / 2
     */
    size = size - 1;
    for (int i = 0; i <= size / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[size - i];
        arr[size - i] = temp;
    }
}

void reverse_array_m2(int arr[], int size) {
    int s = 0, e = size - 1;
    while(s <= e) {
        int temp = arr[s];
        arr[s] = arr[e];
        arr[e] = temp;
        s++;
        e--;
    }
}

int main (int argc, char *argv[]) {
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    int size = 7;
    int arr[size];
    for(int i = 0; i < size; i++) {
        std::cin >> arr[i];
    }
    reverse_array_m2(arr, size);
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
