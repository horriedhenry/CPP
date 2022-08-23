#include<iostream>
using namespace std;

int main(void)
{
    const int r=3,c=3;
    int arr[r][c] = {{1,2,3}, {4,5,6}, {7,8,9}};

    for (int i = 0; i < r; i++)
    {
        for (int j = i; j < c; j++)
        {
            // if (i==j)
            // {
            //     break;
            // }
            // else
            // {
                //swap
                int temp=arr[i][j];
                arr[i][j]=arr[j][i];
                arr[j][i]=temp;
            // }
        }
    }
    //print array
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}