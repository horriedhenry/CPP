#include<iostream>
using namespace std;

int fib(int n) {
    //fib(50) = 12586269025
    if (n==0)
    {
        return 0;//0th fib is 0 (0 based indexing)
    }
    if (n==1)
    {
        return 1;//1st fib is 1 (0 based indexing)
    }
    // return fib(n-1) + fib(n-2);
    int n_minus_1_fib = fib(n-1);

    int n_minus_2_fib = fib(n-2);

    return n_minus_1_fib+n_minus_2_fib;
}

int main(void)
{
    int n=1;//6th fibonacci number
    cout<<fib(6);
    return 0;
}
