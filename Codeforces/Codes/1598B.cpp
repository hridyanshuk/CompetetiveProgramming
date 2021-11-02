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
        int arr[n][5];
        for(int i=0 ; i<n ; i++)
        {
            for(int j=0 ; j<5 ; j++)
            {
                cin>>arr[i][j];
            }
        }
        int grp[n];
        int in=0;
        int count=0;
        for(int i=0 ; i<5 ; i++)
        {
            count=0;
            for(int j=0 ; j<n ; j++)
            {
                if(arr[j][i]==1)
                {
                    count++;
                    grp[in++]=j;
                }
            }
        }


    }

    return 0;
}