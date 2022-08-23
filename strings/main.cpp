//documentation
//https://cplusplus.com/reference/string/string/
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(void)
{
    // string str;
    // cin>>str;
    // cout<<str<<endl;
    // declare string way2
    // string str1(5,'o');//string with 5 'o's
    // cout<<str1<<endl;
    // string str3="string";
    // cout<<str3;

    //input string with spaces (sentense)
    // string str4;
    // getline(cin,str4);
    // cout<<str4<<endl;

    // string concatination
    // string s1="abc",s2="abc";
    // s1+=s2;
    // s1.append(s2);
    // cout<<s1<<endl;
    // cout<<s1<<endl;
    // cout<<s3;

    //access character in string
    // cout<<s1[1];

    //clear function
    // s2.clear();
    // cout<<s2;

    //string comparision
    // cout<<s2.compare(s1)<<endl;//compare s2 with s1 0 if equal 1 if not equal (0-false,1-true)
    // if (s2.compare(s1)==0)
    // {
    //     cout<<"equal";
    // }
    // if (!s2.compare(s1))
    // {
    //     cout<<"equal";
    // }

    //check empty
    // s1.clear();
    // if(s1.empty()) {//if true
    //     cout<<"empty";
    // }
    // if(!s1.empty()) {//if false
    //     cout<<"not empty";
    // }


    //erase function
    string newstr="nincompoop";
    // newstr.erase(3,2);//remove 2 characters starting from index 3 (i.e 'co')
    // cout<<newstr;


    //find function
    // cout<<newstr.find("com");//returns index of the first character where the word start//returns -1 if word,letter notin string


    //insert function->insert a single character at an index,or a string starting from given index(argument)
    // newstr.insert(2,"l");//insert l at 2 index (0 indexing)
    // newstr.insert(3,"top");//insert top starting from index 3 (0 indexing)
    // cout<<newstr;

    //length of string->str.length()/str.size()
    // cout<<newstr.size()<<endl;

    //sub strings -> str.substr(6,4) ==>returns 4 characters starting from index 6 (0 indexing)
    cout<<newstr.substr(6,4)<<endl;


    //string to integer ->stoi(string)
    // string nbr="400";
    // int x=stoi(nbr);
    // cout<<x;

    //integer to string
    // string tostring=to_string(x);
    // cout<<tostring;//x is string


    //sort string (include<algorithm>) -> sort(string.begin(),string.end()) / sort in ascending order
    string sortstr="yzxbcad";
    sort(sortstr.begin(),sortstr.end());
    cout<<sortstr;
    return 0;
}