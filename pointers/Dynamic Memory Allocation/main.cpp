#include<iostream>
using namespace std;

void assign(int *ptr) {
    ptr[0]=10;
    ptr[1]=20;
}

int main(void)
{
    int *p = new int();
    *p=19;

    // int *arr2d = new int[3*3];//2d array (dynamic)
    // *(arr2d+0*0+0)=10;
    // cout<<*(arr2d+0*0+0);

    int *a = new int[4];
    int arr[4];
    assign(arr);
    // cout<<a[1];
    // cout<<arr[1];
    delete[]a;
    delete(p);
    // delete(arr2d);
    a=NULL;
    // arr2d=NULL;
    p=NULL;
    return 0;
}