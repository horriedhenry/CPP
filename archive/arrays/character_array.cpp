#include<iostream>
using namespace std;

int main(void)
{
    const int n=8;
    char a[n+1]="racecarr";//n+1 the character '\0'->end of world/string
    bool flag=true;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != a[(n-1)-i])
        {
            flag=false;
            break;
        }
    }
    if (flag){
        cout<<"palindrome"<<endl;
    }
    else {
        cout<<"!"<<endl;
    }
    return 0;
}
