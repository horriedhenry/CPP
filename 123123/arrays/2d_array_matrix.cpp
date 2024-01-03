#include <iostream>

int main (int argc, char *argv[]) {
    int rows = 3, cols = 2;
    int arr[rows][cols];
    int e = 1;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            arr[i][j] = e;
            e++;
        }
    }

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }


    // print column wise 
    // arr :
    // 1 2
    // 3 4
    // output :
    // 1 3
    // 2 4
    for(int i = 0; i < cols; i++) {
        for(int j = 0; j < rows; j++) {
            std::cout << arr[j][i] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
