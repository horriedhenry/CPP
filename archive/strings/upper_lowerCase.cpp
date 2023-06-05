#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

void inbuilt_function() {
    string str="lowercase";
    transform(str.begin(),str.end(), str.begin(), ::toupper);
    cout<<str<<endl;
    transform(str.begin(),str.end(), str.begin(), ::tolower);
    cout<<str<<endl;
}

int main(void)
{
    string str="henry";
    string LowerUpper = "HoRRied HenrY";
    //convert to uppercase
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] >='a' && str[i]<='z')
        {
            str[i]-=32;
            /* code */
        }
    }
    cout<<str<<endl;
    //convert to lowercase
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] >='A' && str[i]<='Z')
        {
            str[i]+=32;
            /* code */
        }
    }
    cout<<str<<endl;

    //lower to upper vis versa
    for (int i = 0; i < LowerUpper.size(); i++)
    {
        if (LowerUpper[i] >='a' && LowerUpper[i]<='z')
        {
            LowerUpper[i]-=32;
            /* code */
        }
        else if (LowerUpper[i] >='A' && LowerUpper[i]<='Z')
        {
            LowerUpper[i]+=32;
            /* code */
        }
    }
    cout<<LowerUpper<<endl;
    inbuilt_function();
    return 0;
}

