// insert an element in unsorted array to its correct position in sorted array
#include<iostream>
using namespace std;

int main(void)
{
    int arr[5]={3, 5, 2, 1, 4};
    int size=sizeof(arr)/sizeof(arr[0]);
    for (int i = 1; i < size; i++)
    {
        int current = arr[i];
        int j = i-1;
        while (arr[j] > current && j >= 0)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = current;
    }

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    
    return 0;
}