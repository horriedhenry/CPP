// Find the minimum element in the unsorted array and swap it with the element the beginning
#include<iostream>

using namespace std;

int main(void)
{
    int arr[10] = {8, 3, 10, 5, 2, 9, 7, 1, 4, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[i])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}