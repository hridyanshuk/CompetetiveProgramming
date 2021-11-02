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
int MAX(int a, int b)
{
    if(a>b)
    {
        return a;
    }
    
    return b;
    
}
int MIN(int a, int b)
{
    if(a<b)
    {
        return a;
    }
    
    return b;
    
}
void swap(int *a, int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a[3], m;
        cin>>a[0]>>a[1]>>a[2]>>m;
        int n=a[0]+a[1]+a[2];
        FOR(i,0,3)
        {
            FOR(j,i,3)
            {
                if(a[i]>a[j])
                {
                    swap(&a[i], &a[j]);
                }
            }
        }
        int s=a[2]-a[1];
        if(s<a[0])
        {
            s=a[0]-s;
            if(s<=a[1]+1)
            {
                if(m<=n-3)
                    cout<<"YES\n";
                else
                    cout<<"NO\n";
            }
            else
            {
                s=s-a[1];
                if(s-1>m)
                {
                    cout<<"NO\n";
                }
                else
                {
                    cout<<"YES\n";
                }
            }
        }
        else
        {
            s=s-a[0];
            if(s<=1)
            {
                if(m<=n-3)
                    cout<<"YES\n";
                else
                    cout<<"NO\n";
            }
            else
            {
                s=s-1;
                if(s>m)
                {
                    cout<<"NO\n";
                }
                else
                {
                    cout<<"YES\n";
                }
            }
        }
        
    }

    return 0;
}