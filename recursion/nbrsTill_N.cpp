// if n=5 ->print 1,2,3,4,5
#include<iostream>
using namespace std;

void prtNbrs_ascending(int n) {
    //base case
    if (n==0)
    {
        return;
    }
    //recursive case
    prtNbrs_ascending(n-1); // 1 2 3 4 ...n-1
    cout<<n<<endl;
    return;
}

void prtDescending(int n) {
    //base case
    if (n==0)
    {
        return;
    }
    cout<<n<<endl;
    //recursive case
    prtDescending(n-1); // 5 4 3 2..n-1
    // print(n n-1 n-2 n-3 n-4 ...1)
    return;
}

int main(void)
{
    prtDescending(10);
    return 0;
}