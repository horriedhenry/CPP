#include<iostream>
#include<climits>
using namespace std;

int main(void)
{
    int arr[5] = {1,3,4,5,6};
    int maxNo = INT_MIN;
    int minNo = INT_MAX;
    for (int i = 0; i < 5; i++)
    {
        // if(arr[i]>maxNo){
        //     maxNo = arr[i];
        // }
        // if(arr[i]<minNo){
        //     minNo = arr[i];
        // }
        minNo = min(minNo, arr[i]);
        maxNo = max(maxNo, arr[i]);
    }
    cout << "maxNo : " << maxNo << endl << "minNo : " << minNo; 
    return 0;
}
