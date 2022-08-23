#include<iostream>
using namespace std;

int main(void)
{
    int max_length=0;
    int current_length=0;
    char arr[100]="largest sentence word in";
    int i=0;
    int wordStart=0,wordEnd=0;
    while (1)
    {
        if (arr[i]==' ' || arr[i]=='\0') {
            if (current_length>max_length)
            {
                max_length=current_length;
                wordEnd=i-1;
            }
            current_length=0;
        }
        else {
            current_length++;
        }
        if(arr[i]=='\0') {
            break;
        }
        //move to next letter
        i++;
    }
    cout<<max_length<<endl;
    wordStart=(wordEnd-max_length)+1;//+1 to start after space
    for (int i=wordStart;i<=wordEnd;i++)
    {
        cout<<arr[i];
    }
    return 0;
}