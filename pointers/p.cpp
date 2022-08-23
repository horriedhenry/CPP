#include<iostream>
using namespace std;

void inc(int *a) {
    *a+=1;
}

void swap(int *a,int *b) {
    int temp=*a;
    *a=*b;
    *b=temp;
}

int main(void)
{
    // int a=10;
    // int* aptr=&a;
    // cout<<*aptr<<endl;
    // *aptr=20;
    // cout<<a<<endl;
    

    //pointer arithmetic
    // int b=11;
    // int* aptr=&b;
    // cout<<int(aptr)<<endl;
    // aptr+=1;
    // cout<<int(aptr);


    //pointer to array
    // int ar[]={1,2,3,4};
    // cout<<*ar<<endl;//prints first element
    
    //print array elements using pointer
    // int arr[3]={1,2,3};
    // int *arrayPtr=arr;
    // for (int i = 0; i < 3; i++) {
        // cout<<*(arrayPtr+i)<<" ";
        // cout<<*(arr+i)<<" ";
    // }

    //pointer to pointer(double pointer)
    // int a=10;
    // int *ptr=&a;
    // cout<<*ptr<<endl;//10
    // int **doublePtr=&ptr;
    // cout<<"dp : "<<int(**doublePtr);

    //pointer to function
    // int nbr=10;
    //pass by reference
    // inc(&nbr);
    // cout<<nbr;
    int val1=10,val2=12;
    swap(val1,val2);
    cout<<val1<<endl<<val2;
    return 0;
}