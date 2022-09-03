#include<iostream>
using namespace std;

int binSearch(int arr[],int start,int end,int key,int size) {
    if(start>end) {
        return -1;
    }
    int mid=start + (end - start)/2;
    if (arr[mid]==key)
    {
        return mid;
    }
    else if(arr[mid]>key) {
        return binSearch(arr,start,mid-1,key,size);
    }
    else if(arr[mid]>key) {
        return binSearch(arr,mid+1,end,key,size);
    }
}

int main(void)
{
    int arr[5]={11,22,35,40,57};
    int size=5,start=0,end=size-1;
    int key;
    cout<<"key : ";
    cin>>key;
    cout<<binSearch(arr,start,end,key,size);
    return 0;
}