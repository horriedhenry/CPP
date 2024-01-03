#include <cstdio>
#include <cstring>
#include <iostream>

/*

int size(char arr[]) {
    int i = 0, size = 0;
    while(arr[i] != '\0') {
        size++;
        i++;
    }
    return size;
}

int arr_size = 100;
char arr[arr_size]; // input = string
char arr_2[arr_size];

std::cin.getline(arr, arr_size);
std::cin.getline(arr_2, arr_size);
std::cout << "strlen() : " << strlen(arr) << std::endl; // output = 6
std::cout << "strcmp() : " << strcmp_(arr, arr_2) << std::endl;
if(strcmp_(arr, arr_2)) {
    std::cout << "equal" << std::endl;
} else {
    std::cout << "not" << std::endl;
}
std::cout << "strcpy()" << std::endl;
char arr_3[arr_size];
//strcpy(arr_3, arr); // copy the contents of arr_2 to arr_3.
std::cout << "arr_3 strcpy() : " << arr_3 << std::endl;
std::cout << "before strcpy_() : " << arr << std::endl;
strcpy_(arr, arr_2);
std::cout << "strcpy_() : " << arr << std::endl;
char temp[] = "abc"; // adds null terminator (notes)
int i = 0;
while (temp[i] != '\0') {
    std::cout << temp[i] << " ";
    i++;
}
std::cout << std::endl;
strcpy_(arr, temp);
std::cout << "strcpy_() : " << arr << std::endl;

strlen(char_array) - similar to size()

---

strcmp(str1,str2) - compares 2 strings , return type : bool. checks if two strings are equal.
strcmp() returns a non zero value if two string does not match. the non zero value
can be anything.

subtracts each character from two given strings and if all the characters return 0
then strcmp() returns zero.
ex : str1 = string str2 = string
     's' - 's' =  0
     't' - 't' =  0 .....

strcpy(copy_to, copy_from) - copy one sting to another

strncpy(copy_to , copy_from, n_character) - copys first n character 
copy_to = "string" copy_from = "abc" - copies abc to string resulting copy_to to be
"abcing"
strncpy do not copy null terminator.

if n in strncpy() is greater than the length of copy_from then the remaing n characters
would be replaced with null terminator characters
ex : strncpy("string", "abc", 4) the copy_to arrays would be abc , ing will be replaced
with null terminator characters. output = abc
if not strncpy("string", "abc", strlen("abc")) the output would be "abcing".

strcat(s1, s2) - concatinate s2 to s1 i.e add contents of s2 to s1.
s1 = "abc" s1 = "def" 
strcat() will return "abcdef".

*/

bool strcmp_(char s1[], char s2[]) {
    if (strlen(s1) != strlen(s2)) { return false; }
    else {
        for (int i = 0; s1[i] != '\0'; i++) {
            if(s1[i] != s2[i]) { return false; }
        }
        return true;
    }
}

void strcpy_(char to[], char from[]) {
    // TODO : what if the size of two char arrays do not match.
    // TODO : what if the char array does not have a null terminator.
    // TODO : to = string and from is "abc" abc is passed like this strcpy_(s1, "abc")
    // abc does not include null terminator. passing "abc" is not allowed.
    // convertion of string to char arrays is not allowed in c++11.
    int s = strlen(from);
    for(int i = 0; i <= s; i++) {
        to[i] = from[i];
    }
    std::cout << to << std::endl;
}

void strcat_(char s1[], char s2[]) {
    // start concatinating at null terminator i.e from the len() of s1.
    // std::cout << s1[len_s1] << std::endl; return null terminator character.
    // so start concatinating from there.
    int len_s1 = strlen(s1);
    for (int i = 0; i <= strlen(s2); i++) {
        s1[len_s1] = s2[i];
        len_s1++;
        // s1[len_s1 + i] = s2[i];
    }
}

int main (int argc, char *argv[]) {
    freopen("input", "r", stdin);
    int arr_size = 100;
    char arr[arr_size]; // input = string
    char arr_2[arr_size];
    std::cin.getline(arr, arr_size);
    std::cin.getline(arr_2, arr_size);
    strcat_(arr, arr_2);
    std::cout << arr << "\n";
    return 0;
}
