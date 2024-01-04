#include <iostream>

void print_2d_array(int arr[][2], int rows, int cols) {
    // should pass the actual column number that is used for the array that is being
    // passed to this function.
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void print_2d_array_without_const_rows_cols(int arr[][10], int rows, int cols) {
    // if we just use arr[10][10] without arr[rows][cols] we don't need to specify
    // const for rows and cols.
    // just hard code rows and cols (may not be good all the time).
    // better to use const rows cols.
    // i think the reason we need const is coz we cannot change no of cols after 
    // we declare cols it may cause memeory issues and leaks.
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main (int argc, char *argv[]) {
    const int rows = 3, cols = 2; // if we dont use const int rows,cols we cannot
    // pass the twoD array to a function , just gives an error
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

    print_2d_array(arr, rows, cols);

    int arr_witout_const_rows_cols[10][10];
    e = 1;
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            arr_witout_const_rows_cols[i][j] = e;
            e++;
        }
    }
    print_2d_array_without_const_rows_cols(arr_witout_const_rows_cols, 10, 10);
    return 0;
}
