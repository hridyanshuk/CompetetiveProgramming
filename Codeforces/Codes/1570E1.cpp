//Problem 1579 E1
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int ar1[n];
        int ar2[2*n]={0};
        cin>>ar1[0];
        ar2[n]=ar1[0];
        int beg=n-1;
        for(int i=1 ; i<n ; i++)
        {
            cin>>ar1[i];

                if(ar1[i]>ar2[beg+1])
                {
                    ar2[beg+1+i]=ar1[i];
                }
                else
                {
                    ar2[beg]=ar1[i];
                    beg--;
                }

        }

        for(int i=1 ; i<n ; i++)
        {
            cout<<ar2[beg+i]<<" ";
        }
        cout<<ar2[beg+n];
        cout<<endl;

    }
    return 0;
}
