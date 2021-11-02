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
        int n;
        cin>>n;
        int arr[n];
        input(arr, n);
        int x=0;
        bool status=true;
        //int temp[n][2]={0};
        int tin=0;
        int tout=0;
        int count=0;
        while(count<n)
        {
            count++;
            x=0;
            int temp=0;
            for(int i=n-1 ; i>=0 ; i--)
            {
                if(arr[i]==-1)
                {
                    x++;
                }
                else if(arr[i]%(i-x+2)!=0)
                {
                    temp++;
                    arr[i]=-1;
                }

            }

            if(temp==0)
            {
                if(x!=n)
                    status=false;
                break;
            }
        }

        
        if(status)
        {
            cout<<"YES\n";
        }
        else
        {
            cout<<"NO\n";
        }
    }   

    return 0;
}