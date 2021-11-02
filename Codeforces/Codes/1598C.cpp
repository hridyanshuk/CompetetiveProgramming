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

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        input(arr,n);
        int sum=0;
        FOR(i,0,n)
        {
            sum+=arr[i];
        }
        if((sum*(n-2))%n != 0)
        {
            cout<<0<<endl;
        }
        else
        {
            int sum2=(sum*(n-2))/n;
            int sum3=sum-sum2;
            int count=0;
            FOR(i,0,n-1)
            {
                FOR(j,i+1,n)
                {
                    if(arr[i]+arr[j]==sum3)
                        count++;
                }
            }
            cout<<count<<endl;
        }

    }

    return 0;
}