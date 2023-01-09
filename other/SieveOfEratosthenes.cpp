#include<iostream>
using namespace std;

// int sievePrimeFactorization(int size) {
// }
void sievePrimeNumbers(int size) {
    int arr[100]={0};
    for (int i = 2; i < size; i++)
    {
        if (arr[i]==0)
        {
            for (int j = i*i; j < size; j+=i)
            {
                arr[j]=1;
            }
        }
    }

    for (int i = 2; i < size; i++)
    {
        if (arr[i]==0)
        {
            cout<<i<<" ";
        }
    }
}

int main(void)
{
    int size;
    cin>>size;
    sievePrimeNumbers(size);
    return 0;
}
