#include<iostream>
#include<climits>
using namespace std;

int kadane(int arr[], int n) {
    int currSum=0;
    int maxSum=INT_MIN;
    for (int i = 0; i < n; i++)
    {
        currSum+=arr[i];
        if (currSum<0)
        {
            currSum=0;
        }
        maxSum=max(maxSum,currSum);
    }
    return maxSum;
}

int main(void)
{
    int arr[5]={-1,2,4,-4,5},n=5;
    cout<<kadane(arr,n);
    return 0;
}
