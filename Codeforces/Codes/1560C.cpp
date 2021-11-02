//Problem 1560 C
#include <iostream>
#include <math.h>
using namespace std;


int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n,row,col;
        cin>>n;
        int m=sqrt(n);
        row=1;
        col=m;
        if(n==m*m)
        {
            row=m;
            col=1;
        }
        else
        {
            col=m+1;
            int a=n-m*m;
            if(a>m)
            {
                a=a-m-1;
                col-=a;
                row=m+1;
            }
            else
            {
                col=m+1;
                row=a;
            }
        }
        cout<<row<<" "<<col<<endl;
    }
    return 0;
}
