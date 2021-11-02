#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
using namespace std;

typedef long long ll;

#define FOR(i,m,n) for(int i=m ; i<n ; i++)

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

ll bin_int(int x)
{
    ll binary=0;
    while(x!=0)
    {
        binary=binary*10+x%2;
        x=x/2;
    }
    return binary;
}

ll xNnor(int a, int b)
{
    ll bina=bin_int(a);
    ll binb=bin_int(b);
    int i=1;
    ll xnor=0;
    while(a!=0 && b!=0)
    {
        int a_=a%10;
        int b_=a%10;
        xnor=xnor*10+abs(a_-b_);
        a/=10;
        b/=10;
    }
    while(a!=0)
    {
        xnor*=10;
        xnor+=a%10;
        a/=10;
    }
    while(b!=0)
    {
        xnor*=10;
        xnor+=b%10;
        b/=10;
    }
    return xnor;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, x;
        cin>>n>>x;
        int arr[n];
        input(arr,n);
        if(x>=n)
        {
            cout<<"NO\n";
        }
        else if(x<=n/2)
        {
            cout<<"YES\n";
        }
        else
        {
            int i=0;
            int rec[n]={0};
            for(int j=0 ; j<n ; j++)
            {
                
            }
        }
        
    }

    return 0;
}