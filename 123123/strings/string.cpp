#include <algorithm>
#include <iostream>
#include <string>


/*

References : (https://cplusplus.com/reference/string/string/)

str.begin() - returns pointer to first character in string.
str.end() - returns pointer to last character in string.

std::string::iterator - creates an iterator to iterate through the each character
in string.
iterator stackoverflow discussions :
https://softwareengineering.stackexchange.com/questions/389748/should-i-always-use-iterators-when-working-with-strings
https://stackoverflow.com/questions/1995109/why-use-stringiterator-rather-than-index
https://stackoverflow.com/questions/131241/why-use-iterators-instead-of-array-indices


*/

void print_string() {
    std::string str ("Test String");
    // use iterator to print each character in string
    for (std::string::iterator it = str.begin(); it != str.end(); it++) {
        // std::cout << *it << std::endl;
        std::cout << *it;
    }
    std::cout << std::endl;
    // or can also use auto
    for (auto it = str.begin(); it != str.end(); it++) {
        // std::cout << *it << std::endl;
        std::cout << *it;
    }
    std::cout << std::endl;
}

void string_input() {
    std::string str;
    // std::cin >> str; // cin stops taking input once it encounters a space character
    // so use getline() - takes three parameters (string, size, delimeter) delimeter is optional.
    // but as we dont know the size of the string str , i.e the speciality of string class
    // we do not need to specify the size or null terminator it automaticall set those.
    // So we use getline() function differently.
    getline(std::cin, str);
    std::cout << str << std::endl;// allows space (input = string string string)
    // output = string string string.
}

void inbuilt_string_methods() {
    std::string str ("Test");
    std::cout << "str = " << str << std::endl;
    std::cout << str.length() << std::endl;
    std::cout << str.size() << std::endl;
    std::cout << str.capacity() << std::endl; // return size of allocated storage for the string.
}

void add_two_strings() {
    std::string str1 ("str1");
    std::string str2 ("str2");
    std::string str4 = ""; // or can also do the below
    // str4 += str1 + str2;
    // str4.append(str1.append(str2));
    // std::cout << "str4 += str1 + str2 -> " << str4 << std::endl;
    // std::cout << "str4.append(str1.append(str2)) => " << str4 << std::endl;
    // str4.clear();
    // std::cout << "clear()" << str4 << std::endl;
    // compare str1 with str2
    /*
    the reason why the code below prints not equal is because compare() function 
    returns 0 if two strings match but in terms of boolean expressions 0 if false
    hence it prints not equal. to solve this use !.
    If compare function has a boolean return type then the code below works.
    if (str1.compare(str2)) {
        std::cout << "equal" << std::endl;
    } else {
        std::cout << "not equal" << std::endl;
    }
    when compare() returns 0 - !0 becoms true , so it prints equal.
    when two strings do not match compare() returns a non zero value and in that case
    !non_zero value is a zero and zero is false so it prints not equal.
    compare returns -1 if not matched so !-1 is 0 and 0 is false.
    if (!str1.compare(str2)) {
        std::cout << "equal" << std::endl;
    } else {
        std::cout << "not equal" << std::endl;
    }
    or we can use something like this
    if (str1.compare(str2) == 0) {
        std::cout << "str1 == str2" << std::endl;
    } else {
        std::cout << "str1 != str2" << std::endl;
    }
    */
    if (!str1.compare(str2)) {
        std::cout << "str1 == str2" << std::endl;
    } else {
        std::cout << "str1 != str2" << std::endl;
    }
    std::cout << str1.compare(str2) << std::endl;
}

void check_empty() {
    // empty() returns 0 if not empty and non zero value if empty.
    std::string str ("string");
    if(!str.empty()) { // we know why ! is used. check add_two_strings() func.
        std::cout << "not empty" << std::endl;
    } else {
        std::cout << "empty" << std::endl;
    }
}

void erase() {
    std::string str ("String");
    // str.erase(3,0); // starting from index 3 remove/delete 0 characters. output = String
    // str.erase(3,1); // starting from index 3 remove/delete 1 characters. output = Strng
    // str.erase(3,3); // starting from index 3 remove/delete 3 characters. output = Str
    std::cout << str << std::endl;
}

void insert_method() {
    std::string str ("String");
    str.insert(0, "lol"); // starting from index 0 insert "lol" to str.
    // indexing starts form 0.
    std::cout << str << std::endl;

}

void replace_func_or_method() {
    std::string str ("aaring");
    std::string str1 ("staang");
    std::cout << str << std::endl;
    std::string replace ("st");
    std::string replace1 ("ri");
    std::cout << "str  : " << str << std::endl;
    str.replace(0,replace.length(), replace); // starting from index (indexing starts form 0 so 2 means 0,1,2) 2 replace 2 characters
    std::cout << "str  : " << str << std::endl;
    std::cout << "str1 : " << str1 << std::endl;
    str1.replace(2,replace.length(), replace1); // starting from index (indexing starts form 0 so 2 means 0,1,2) 2 replace 2 characters
    std::cout << "str1 : " << str1 << std::endl;
    // which is length of the replace string with the replace string i.e "ri".
    // after position 2 (**imp**)
}

void substring() {
    std::string str ("string");
    std::cout << str.substr(2, 3) << std::endl; // starting form index 2 (i.e 0,1,2) print
    // substring of length 3 i.e "rin" in out case.
    // indexing for 3 also goes like this (0,1,2)
    // i think what it does is adds 0 to 2 and 1 to 2 and 2 to 2 which gives
    // 2 3 4 and at index 2 3 4 we have "rin" which explains the output.
}

void convert_str_to_int_stoi() {
    std::string str_num = "101";
    int num = std::stoi(str_num);
    std::cout << num << std::endl;
}

void convert_int_to_string() {
    int num = 101;
    std::string str_num = std::to_string(num);
    std::cout << str_num << std::endl;
}

void sort_string() {
    std::string str = "zyx";
    std::cout << "str = " << str <<std::endl;
    std::sort(str.begin(), str.end());
    std::cout << "sorted str = " << str <<std::endl;
}

int main (int argc, char *argv[]) {
    sort_string();
    return 0;
}
