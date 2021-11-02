#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
using namespace std;

typedef long long ll;

#define FOR(i,m,n) for(int i=m ; i<n ; i++)
#define XOR(a,b) ((a)|(b))-((a)&(b))

const ll MOD_N=1000000007;

ll factModn(ll m, ll n)
{
    ll factorial=1L;
    for(ll i=1L ; i<=m ; i++)
    {
        factorial=(factorial*i)%n;
    }
    return factorial;
}

void input(int *arr, int n)
{
    FOR(i,0,n)
    {
        cin>>arr[i];
    }
}
void output(int *arr, int n)
{
    FOR(i,0,n)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
bool prime(int n)
{
    int r=sqrt(n)+1;
    FOR(i,0,r)
    {
        if(n%i==0)
        {
            return false;
        }
    }
    return true;
}

int xorTillN(int n)
{
    int c=n%4;
    switch (c)
    {
    case 0:
        return n;
        break;
    case 1:
        return 1;
        break; 
    case 2:
        return n+1;
        break;
    default:
        return 0;
        break;
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, a, b;
        cin>>n>>a>>b;
        char s[n+1];
        cin>>s;
        int nof0=0;
        int nof1=0;
        if(s[0]=='0')
        {
            nof0++;
        }
        else
        {
            nof1++;
        }
        FOR(i,1,n)
        {
            if(s[i]=='0' && s[i-1]=='1')
            {
                nof0++;
            }
            else if(s[i]=='1' && s[i-1]=='0')
            {
                nof1++;
            }
        }
        int max=n*a;
        if(b>=0)
        {
            max+=n*b;
        }
        else
        {
            if(nof1>0)
            {
                if(s[0]=='1')
                    max=max+b*(nof0+1);
                else
                    max=max+b*(nof1+1);
            }
            else
            {
                max=max+b*nof0;
            }
        }
        cout<<max<<endl;
    }

    return 0;
}