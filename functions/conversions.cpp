#include<climits>
#include<iostream>
using namespace std;

void binaryToDecimal(int num) {
    int ans=0;
    int basenbr=1;//2^0=1
    while (num>0)
    {
        int lastdig=num%10;
        ans+=basenbr*lastdig;
        basenbr*=2;//base 2 1->1*2,2*2....
        num/=10;
    }
    cout<<ans;
}

void octalToDecimal(int num) {
    int ans=0;
    int basenbr=1;
    while (num>0)
    {
        int lastdig=num%10;
        ans+=lastdig*basenbr;
        basenbr*=8;
        num/=10;
    }
    cout<<ans;
}

void hexadecimalToDecimal(string num) {
    int ans=0;
    int base=1;
    int s = num.size();
    for (int i = s-1; i>=0; i--)
    {
        if (num[i] >= '0' && num[i] <= '9')
        {
            ans+=base*(num[i]-'0');
            // char c='2'; // for ->num[i]-'0'
            // char d='0';
            // int a=c-d;
            // cout<<a;
        }
        else if (num[i] >= 'A' && num[i] <= 'F')
        {
            ans+=base*(num[i] - 'A' +10);
        }
        base*=16;
    }
    cout<<ans;
}

void decimalToBinary(int num) {
    //https://youtu.be/EQeq0FUOMWw?t=407
    int ans[32];
    int i=0;
    while (num)
    {
        int rem=num%2;
        num/=2;
        ans[i]=rem;
        i++;
    }
    for (int j = i-1; j >= 0; j--)
    {
        cout<<ans[j]<<" ";
    }
}

void decimalToOctal(int num) {
    //https://youtu.be/lYnPK1svd-4?list=PLfqMhTWNBTe0b2nM6JHVCnAkhQRGiZMSJ&t=462
}

void decimalToHexadecimal(int num) {
    //https://youtu.be/lYnPK1svd-4?list=PLfqMhTWNBTe0b2nM6JHVCnAkhQRGiZMSJ&t=520
}

int main(void)
{
    int input;
    cin>>input;
    decimalToBinary(input);
    return 0;
}