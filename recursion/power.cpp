#include<iostream>
using namespace std;

int power(int n,int p) {
    //base case
    if(p==0) {
        return 1;
    }
    //recursive case
    int Power_p_minus_1 = power(n,p-1);
    //ans
    return n * Power_p_minus_1;
}

int main(void)
{
    int n=4,pow=2;
    cout<<power(n,pow);//4 raised to power 2
    return 0;
}