#include <climits>
#include <iostream>
#include <map>
#include <string>

#define endl std::endl

int main (int argc, char *argv[]) {
    std::string input = "blaah blaaaaah blaaaaaaah bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb";
    std::map<char, int> freq;
    int max = INT_MIN;
    char freq_char;
    for (int i = 0; i < input.length(); i++) {
        // check if the already exist, if not make a pair
        char curr_char = input[i];
        if (freq.find(input[i]) == freq.end()) {
            // if there is not pair with the current char then just add one and make the sum 0
            freq[curr_char] = 0;
        }
        freq[curr_char]++;
    }
    for (auto it = freq.begin(); it != freq.end(); ++it) {
        if(it->second > max) {
            max = it->second;
            freq_char = it->first;
        }
    }
    std::cout << freq_char << endl;
    return 0;
}
