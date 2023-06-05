#include<iostream>
using namespace std;

int binRec(int arr[],int start, int end,int key) {
    if (start > end)
    {
        return -1;
    }
    int mid = (start + end)/2;
    if (arr[mid]==key)
    {
        return mid;
    }
    else if (key > arr[mid])
    {
        return binRec(arr,mid+1,end,key);
    }
    else if (key < arr[mid])
    {
        return binRec(arr,start,mid-1,key);
    }
}

int main(void)
{
    int arr[11] = {0,1,2,3,4,5,6,7,8,9};
    int size = sizeof(arr)/sizeof(arr[0]);
    int pos = binRec(arr,0,size-1,0);
    (pos == -1) ? cout<<"Element not found"<<endl : cout<<"Element found at index : "<<pos;
    return 0;
}
