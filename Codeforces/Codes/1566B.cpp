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

int mexSub(char *s, int n)
{
    int c0=0, c1=0;
    FOR(i,0,n)
    {
        if(s[i]=='0')
        {
            c0++;
            if(c1>0 && c0>0)
                break;
        }
        else
        {
            c1++;
            if(c1>0 && c0>0)
                break;
        }
    }
    if(c1>0 && c0>0)
    {
        return 2;
    }
    else if(c1>0 && c0==0)
    {
        return 0;
    }
    else if(c0>0 && c1==0)
    {
        return 1;
    }
    
}
int memo(int *r, int n, char *s, int len)
{
    if(r[n]>=0)
    {
        return r[n];
    }
    else
    {
        for(int i=0 ; i<n ; i++)
        {

        }
    }
    

    
    return 0;
}

int min(char *s, int n)
{
    int r[n];
    FOR(i,0,n)
    {
        r[i]=-1;
    }
    return memo(r, n, s, n);

}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        char s[100000];
        cin>>s;
        int len=strlen(s);

    }

    return 0;
}