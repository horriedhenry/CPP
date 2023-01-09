#include<iostream>

using namespace std;

int linear_search(int *arr, int key) {
    for (int i = 0; i < 10; i++)
    {
        if (*(arr + i) == key)
        {
            return i;
        }
    }
    return -1;
}

int main(void)
{
    int arr[10] = {1,2,4,5,6,7,8,9,10,11}, key, pos;
    cout << "key : ";
    cin >> key;
    cout << linear_search(arr,key);
    return 0;
}
