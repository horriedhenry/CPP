// reapetedly swap two adjacent values if they are in wrong order
#include<iostream>

using namespace std;

int main(void)
{
    int arr[10] = {8, 3, 10, 5, 2, 9, 7, 1, 4, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    int counter=1;
    while (counter < size)
    {
        for (int i = 0; i < size - counter; i++)
        {
            if (arr[i] > arr[i+1])
            {
                int temp = arr[i+1];
                arr[i+1] = arr[i];
                arr[i] = temp;
                /* code */
            }
        }
        counter++;
    }

    // print sorted array
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
