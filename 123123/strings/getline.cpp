#include <iostream>

/*

Limitations of cin and cout and size of char_arr

say we have arr[3]; the no of character arr can store are 2 the last one is to 
store null terminator i.e '\0'.
if we do cin and give 3 characters as input .....
cin>>arr; and we give and input i.e abc and do cout i.e
cout >> arr; this will crash and start printing garbage values as we dont have 
a null terminator. the program will crash if dealing with critical memory

cin will stop taking input once it encounters a space or tab or a new line.

so we use cin.getline(char_arr[size], size_of_char_arr, delimiter)
by default delimiter is new line character (\n). we can also specify one.

cin.getline() will stop taking input once it encounters a new line (\n).

*/

int main (int argc, char *argv[]) {
    int size = 10;
    char char_array[size];
    // std::cin.getline(char_array, size);
    // std::cin.getline(char_array, 3); // input = henry , size 3 is allowed
    // std::cout << char_array << std::endl; // output = he (1 for null character).

    // std::cin.getline(char_array, 100); // not valid size should be <= 10 coz we
    // specified size = 10.

    // specify a delimiter
    std::cin.getline(char_array, size, ' '); // input = horried henry
    std::cout << char_array << std::endl; // output = horried 
    // as we specified space is the delimiter character so cin will stop taking
    // input once it encounters space character.
    return 0;
}
