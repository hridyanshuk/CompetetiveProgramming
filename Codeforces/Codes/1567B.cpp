#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
using namespace std;

typedef long long ll;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a, b;
        cin>>a>>b;
        int num=0;
        num+=a;
        int c=(a-1)%4;
        int XOR;
        if(c==0)
            XOR=a-1;
        else if(c==1)
            XOR=1;
        else if(c==2)
            XOR=a;
        else if(c==3)
            XOR=0;
        if(XOR==b)
            cout<<num<<endl;
        else
        {
            int temp=(XOR|b)-(XOR&b);
            if(temp==a)
            {
                num+=2;
            }
            else
            {
                num+=1;
            }
            cout<<num<<endl;
        }
    }

    return 0;
}