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
        int x, y;
        cin>>x>>y;
        int p1p2=y/x;
        int rem=y%x;
        
        int div=0;
        int n=0;
        bool e=false;
        if(p1p2==0)
        {
            p1p2=y/x;
            div=1;
        }
        int arr[p1p2]={0};
        FOR(i,1,p1p2/2+1)
        {
            if(p1p2%i==0)
            {
                arr[div++]=i;
            }
        }
        
        arr[div++]=p1p2;
        output(arr, div);
        FOR(i,0,div)
        {
            int temp=arr[i]+1;
            if(rem%temp==0)
            {
                int z=rem/temp;
                int tempn=x*(p1p2/arr[i])+z;
                if(tempn%x == y%tempn == z)
                {
                    e=true;
                    n=tempn;
                }
                
            }
            if(e==true)
            {
                break;
            }
        }
        
        cout<<n<<endl;
    }

    return 0;
}