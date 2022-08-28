//nth fibonacci number
#include<iostream>
using namespace std;

int fibonacci(int n) {
    //base condition
    if (n==0)
    {
        return 0;
    }
    if (n==1)
    {
        return 1;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}

int main(void)
{
    int ans = fibonacci(4);
    cout<<ans;
    return 0;
}