#include<iostream>
using namespace std;

void cont_iterative(int n) {
    int count=0;
    while (n!=0)
    {
        n/=10;
        count++;
    }
    cout<<count<<endl;
}

void count_recursive(int n) {
    if (n==0)
    {
        return;
    }
    // count++;
    count_recursive(n/=10);
}

int main(void)
{
    // count_recursive(12);
    // cout<<count;
    return 0;
}
