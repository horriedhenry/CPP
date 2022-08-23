#include<iostream>
#include<climits>
using namespace std;

void cumulativeSum(int arr[],int size) {
    // https://www.codingpanel.com/lesson/find-the-maximum-subarray-sum-in-on2-time-naive-method/
    // TODO :- lecture 8.6 (https://youtu.be/0JYgnhnZFcE?list=PLfqMhTWNBTe0b2nM6JHVCnAkhQRGiZMSJ&t=687)
    // int currSum[6]; 
    // currSum[0] = 0;
    // for (int i = 1; i < size; i++) {
    //     currSum[i]=currSum[i-1]+arr[i-1];
    // }
    // int maxSum = INT_MIN;
    // for (int i = 1; i <= size; i++) {
    //     int sum=0;
    //     for (int j = 0; j < i; j++) {
    //         sum = currSum[i]-currSum[j];
    //         maxSum = max(sum,maxSum);
    //     }
    // }
    // cout << maxSum;
}

void bruteForce(int arr[], int size) {
    int maxNo = INT_MIN;
    for (int i = 0; i < size; i++)
    {
        for (int j = i; j < size; j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum+=arr[k];
            }
            maxNo=max(maxNo,sum);
        }
    }
    cout << maxNo;
    // timecomplexity : 0(n3)
}

void kadanesAlgorithm(int arr[], int size) {
    int currSum=0;
    int maxSum = INT_MIN;
    for (int i = 0; i < size; i++) {
        currSum+=arr[i];
        if (currSum<0)
        {
            currSum=0;
        }
        maxSum=max(maxSum,currSum);
        // cout << maxSum << " ";
    }
    // cout << endl;
    cout << maxSum;
}

int main(void)
{
    int arr[5]={-1,4,-6,7,-4};
    kadanesAlgorithm(arr,5);
    return 0;
}