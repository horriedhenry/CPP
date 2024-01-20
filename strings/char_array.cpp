#include <iostream>

// keywords : garbage value, anything after '\0' in char arr

int length(char arr[]) {
    int i = 0, length = 0;
    while(arr[i] != '\0') {
        i++;
        length++;
    }
    return length;
}

int main (int argc, char *argv[]) {
    char arr[] = "string";
    std::cout << arr << std::endl;
    int size = sizeof(arr)/sizeof(arr[0]);
    std::cout << "size : " << size << "\n";
    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
        std::cout << arr[i];
    }
    int i = 0;
    while(arr[i] != '\0') {
        std::cout << arr[i];
        i++;
    }
    std::cout << std::endl;

    // char arr[10];
    // std::cin >> arr; // input = "string"
    // arr[6] = 'b'; // replace '\0' with b and adds '\0' after b
    // arr[8] = 'b'; // cout ignores this coz there is is a null terminator before
    // index 8.
    // std::cout << arr << "\n"; // prints "string" (as the input is string).
    // as we know cin >> arr; will add a null terminator i.e '\0'
    // if we use cin to take input for the char array and then try to modify
    // the array and add a new char at 8 and try to print the char arr using
    // cout << arr; it outputs "string".


    char arr_1[10] = "string";
    arr_1[6] = 'b';
    std::cout << arr_1 << "\n";
    // replace null terminator with b and then adds null terminator after b in
    // char arr_1.

    // Add null 
    arr_1[2] = '\0';
    std::cout << arr_1 << "\n"; // output "st". cout prints till it finds null
    // terminator. similar to while loop above.

    // length of char array
    std::cout << length(arr_1) << "\n"; // 6
    return 0;
}
