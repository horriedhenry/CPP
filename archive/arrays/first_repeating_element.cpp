#include<iostream>
using namespace std;

void insertion_sort(int arr[], int size) {
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
}

void rep_ele_loop(int arr[], int size) {
    for (int i = 0; i < size; i++)
    {
        int curr = arr[i];
        for (int j = i+1; j < size; j++)
        {
            if (arr[j] == curr)
            {
                cout << curr << " : " << i+1 <<endl;
                return;
            }
        }
    }
}

int rep_ele_sort(int arr[], int size) {
    for (int i=1; i<=size; i++)
    {
        if (arr[i] == arr[i+1])
        {
            return i;
        }
        
    }
}

int main(void)
{
    int arr[7]={1,3,7,4,5,3,7};
    int size=sizeof(arr)/sizeof(arr[0]);
    // rep_ele_loop(arr,size);
    insertion_sort(arr,size);
    int rep_index = rep_ele_sort(arr, size);
    cout << arr[rep_index] << ":" << rep_index;
    return 0;
}
