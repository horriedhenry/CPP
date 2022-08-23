#include<iostream>
using namespace std;

int main(void)
{
    const int n1=3,n2=4,n3=3;
    int m1[n1][n2]={{2,4,1,2}, {8,4,3,6}, {1,7,9,5}} ,m2[n2][n3]={{1,2,3}, {4,5,6}, {7,8,9}, {4,5,6}}; // n1xn2 and n2xn3(n1xn3->result matrix)
    int res[n1][n3];
    //[3][4] and [4][3]
    // for (int i = 0; i < n1; i++)
    // {
    //     for (int j = 0; j < n3; j++)
    //     {
    //         res[i][j]=0;
    //     }
    // }
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n3; j++) {
            int resl=0;
            for (int k = 0; k < n2; k++) {
                // res[i][j]+=m1[i][k]*m2[k][j];
                resl+=m1[i][k]*m2[k][j];
            }
            res[i][j]=resl;
        }
    }

    //print result
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n3; j++)
        {
            cout<<res[i][j]<<" ";
        }cout<<endl;
    }
    return 0;
}