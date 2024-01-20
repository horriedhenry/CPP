#include <iostream>

int size(char arr[]) {
    int i = 0, size = 0;
    while(arr[i] != '\0') {
        size++;
        i++;
    }
    return size;
}

void reverse(char arr[]) {
    int s = size(arr);
    int e = s - 1;
    for(int i = 0; i < s / 2; i++) {
        char temp = arr[i];
        arr[i] = arr[e - i];
        arr[e - i] = temp;
    }
    std::cout << arr << std::endl;
}

int main (int argc, char *argv[]) {
    freopen("input", "r", stdin);
    int arr_size = 20;
    char arr[arr_size];
    std::cin.getline(arr, arr_size);
    std::cout << arr << std::endl;
    reverse(arr);
    return 0;
}
