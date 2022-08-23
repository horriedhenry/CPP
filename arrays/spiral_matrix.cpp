#include<iostream>
using namespace std;

int main(void)
{
    const int n=4,m=4;
    int arr[n][m]={{ 1, 2, 3, 4 },{ 5, 6, 7, 8 },{ 9, 10, 11, 12 },{ 13, 14, 15, 16 }};
    int rowStart=0,rowEnd=n-1,colStart=0,colEnd=m-1;

    //spiral order matrix
    while(rowStart <= rowEnd && colStart<=colEnd)
    {
        for(int i = colStart ; i <= colEnd; i++) {
            cout<< arr[rowStart][i]<<" ";
        }
        rowStart ++;
        cout<<endl;

        // print last column value of each row
        for(int i = rowStart; i <= rowEnd; i++) {
            cout << arr[i][colEnd]<<" ";
        }
        colEnd --;
        cout<<endl;

        // print bottom most row
        for (int i = colEnd; i >= colStart; i--) {
            cout << arr[rowEnd][i]<<" ";
        }
        rowEnd --;
        cout<<endl;

        // print values first column of each row
        for (int i = rowEnd; i >= rowStart; i--) {
            cout << arr[i][colStart]<<" ";
        }
        colStart ++;
        cout<<endl;
    }
    return 0;
}