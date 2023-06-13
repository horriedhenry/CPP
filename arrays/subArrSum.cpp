#include <iostream>
#include <stdio.h>

void printSubArraySums(int arr[], int& size) {
    // [1, 2, 2]
    // sub arrays , sums
    // 1 = 1
    // 1 2 = 3
    // 1 2 2 = 5
    // 2 = 2
    // 2 2 = 4
    // 2 = 2
    int sum = 0;
    for(int i = 0; i < size; i++) {
        sum = 0;
        for(int j = i; j < size; j++) {
            sum += arr[j];
            std::cout<<sum<<"\n";
        }
    }
}

void printAllPossibleSubarrays(int arr[], int& size) {
    int sum = 0;
    for(int i = 0; i < size; i++) {
        for(int j = i; j < size; j++) {
            sum = 0;
            std::cout<<"[";
            for(int k = i; k <= j; k++) {
                sum += arr[k];
                std::cout<<arr[k];
                if(k == j) {
                    continue;
                }
                else{
                    std::cout<<", ";
                }
            }
            std::cout<<"] = "<<sum<<"\n";
        }
    }
}

int main (int argc, char *argv[]) {
    int arr[3] = {1,2,2};
    int size = sizeof(arr)/sizeof(arr[0]), sum = 0;
    printSubArraySums(arr, size);
    std::cout<<"-----------------"<<std::endl;
    printAllPossibleSubarrays(arr, size);
    return 0;
}
