#include<iostream>
using namespace std;

int main(void)
{
    const int n=4,m=4;
    int arr[n][m]={{1,4,7,11}, {2,5,8,12}, {3,6,9,16}, {10,13,14,17}};
    int row=0,col=m-1,key=20;
    bool found=false;
    while (row<=n && col >= 0) {
        if(arr[row][col]==key) {
            found = true;
            break;
        }
        if(arr[row][col]>key) {
            col--;
        }
        else {
            row++;
        }
    }
    if(found) {
        cout<<"found"<<"["<<row<<"]"<<"["<<col<<"]";
    }
    else {
        cout<<"not found";
    }
    return 0;
}
