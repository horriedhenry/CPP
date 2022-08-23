#include<iostream>

using namespace std;

int binary_search(int arr[],int size, int key) {
    int start=0, end=size;
    while (start <= end)
    {
        int mid=(start + end)/2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (key > arr[mid])
        {
            start=mid+1;
        }
        else if (key < arr[mid])
        {
            end=mid-1;
        }
    }
    return -1;
}

int main(void)
{
    int arr[10] = {1,2,4,5,6,7,8,9,10,11}, key, size = 10;
    cout << "key : ";
    cin >> key;
    cout << binary_search(arr,size,key);
    return 0;
}

// pointer to array
// int binary_search(int *arr,int size, int key) {
//     int start=0, end=size;
//     while (start <= end)
//     {
//         int mid=(start + end)/2;
//         if (*(arr + mid) == key)
//         {
//             return mid;
//         }
//         else if (key > *(arr + mid))
//         {
//             start=mid+1;
//         }
//         else if (key < *(arr + mid))
//         {
//             end=mid-1;
//         }
//     }
//     return -1;
// }