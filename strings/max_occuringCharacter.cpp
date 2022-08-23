#include<iostream>
#include<string>
#include<algorithm>
#include<climits>
using namespace std;

void method0() {
    string str="fjlalaia";
    int Count,maxCount=INT_MIN;
    char maxCountChar;
    for (int i = 0; i < str.size(); i++)
    {
        Count = count(str.begin(),str.end(),str[i]);
        if (Count>maxCount)
        {
            maxCount=Count;
            maxCountChar=str[i];
        }
    }
    cout<<maxCount<<" "<<maxCountChar;
}

int main(void)
{
    string s="asdfdfdaferafdfads";
    int freq[26];
    for (int i = 0; i < 26; i++)
    {
        freq[i]=0;
    }

    for (int i = 0; i < s.size(); i++)
    {
        freq[s[i]-'a']++;
    }

    int maxCount=INT_MIN;
    char ans;

    for (int i = 0; i < 26; i++)
    {
        if (freq[i]>maxCount)
        {
            maxCount=freq[i];
            // cout<<i<<endl;
            ans=i+'a';
        }
    }
    cout<<maxCount<<" "<<ans<<endl;
    // char news='a'+3;
    // cout<<news;
    return 0;
}