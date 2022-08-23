#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(void)
{
    string nbr="291843";
    sort(nbr.begin(),nbr.end(), greater<int>());
    cout<<nbr;
    return 0;
}