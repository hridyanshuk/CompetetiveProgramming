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

int MAX(int a, int b)
{
    if(a>b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a, b, c;
        cin>>a>>b>>c;
        int m=MAX(a,b);
        m=MAX(m,c);
        if(a==m)
        {
            if(a==b||a==c)
                cout<<1<<" ";
            else
                cout<<0<<" ";
        }
        else
        {
            cout<<m-a+1<<" ";
        }
        if(b==m)
        {
            if(b==c||b==a)
                cout<<1<<" ";
            else
                cout<<0<<" ";
        }
        else
        {
            cout<<m-b+1<<" ";
        }
        if(c==m)
        {
            if(c==b||a==c)
                cout<<1<<"\n";
            else
                cout<<0<<"\n";
        }
        else
        {
            cout<<m-c+1<<"\n";
        }


    }

    return 0;
}