#include<iostream>
using namespace std;

void search(int arr[3][3], int key) {
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (arr[i][j]==key)
            {
                cout<<"["<<i<<"]"<<"["<<j<<"]";
                return;
            }
        }
    }
}

int main(void)
{
    const int rows=3,cols=3;
    int arr[rows][cols];
    int rownumber;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin>>arr[i][j];
        }
    }

    // print
    cout<<endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    search(arr,6);
    return 0;
}
