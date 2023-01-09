// recursion : problem depends on a problem of the same nature but with smaller input size
#include<iostream>
using namespace std;

int sumTillN(int n) {
    if (n==0)
    {
        return 0;
    }
    int prevSum=sumTillN(n-1);
    return n+prevSum;
    
}

int fact(int n) {
    if (n==0)
    {
        return 1;
    }
    int Fact = fact(n-1);
    return n*Fact;
}

int main(void)
{
    cout<<fact(5);
    return 0;
}
//principle of mathmatical indection
