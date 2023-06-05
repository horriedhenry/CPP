#include<iostream>
#include<climits>
using namespace std;

int main(void)
{
    int arr[6] = {1,0,5,4,6,8};
    int mx = INT_MIN;
    int size=sizeof(arr)/sizeof(arr[0]);
    for (int i = 0; i < size; i++)
    {
        mx = max(mx, arr[i]);
        cout << mx << " ";
    }
    return 0;
}
