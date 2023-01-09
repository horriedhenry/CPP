#include<iostream>
using namespace std;

int sum(int n) {
    if(n==0) {
        return 0;
    }
    return n%10+sum(n/10);
}

int prod(int n) {
    if(n%10==n) {
        return n;
    }
    return n%10*prod(n/10);
}

void test(int n) {
    if (n==0)
    {
        return;
    }
    cout<<n;
    test(n--);
}

int main(void)
{
    int a=5,b;
    b=a--;
    cout<<b;
    cout<<a;
    return 0;
}
