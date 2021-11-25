#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
using namespace std;

typedef long long ll;

#define FOR(i,m,n) for(int i=m ; i<n ; i++)
#define XOR(a,b) ((a)|(b))-((a)&(b))
#define YES cout<<"YES\n"
#define NO cout<<"NO\n"

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
    FOR(i,2,r)
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

void delFromArr(int *arr, int i, int *n)
{
    FOR(j,i,*n-1)
    {
        arr[j]=arr[j+1];
    }
    *n=*n-1;
}

int MIN(int a, int b)
{
    if(a<b)
    {
        return a;
    }
    return b;
}

void diff(int *a, int *b, int *arr, int n)
{
    FOR(i,0,n)
    {
        arr[i]=a[i]-b[i];
    }
}

int solve(int *arr, int n)
{
    int sum=0;
    if(arr[0]!=0)
    {
        int t=arr[0];
        FOR(i,0,n)
        {
            arr[i]=arr[i]-t;
        }
        sum=sum+abs(t);
    }
   
    FOR(i,2,n+1)
    {
        if(prime(i))
        {
            if(arr[i-1]!=0)
            {
                int t=arr[i-1];
                FOR(j,0, n/i)
                {
                    arr[i*(j+1)-1]=arr[i*(j+1)-1]-t;
                }
                sum=sum+abs(t);
            }
        }
    }
   
    FOR(i,4,n+1)
    {
        if(!prime(i))
        {
            if(arr[i-1]!=0)
            {
                int t=arr[i-1];
                FOR(j,0, n/i)
                {
                    arr[i*(j+1)-1]=arr[i*(j+1)-1]-t;
                }
                sum=sum+abs(t);
            }
        }
    }
  
    return sum;
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    int b[n];
    input(a, n);
    input(b,n);
    int q;
    cin>>q;
    int arr[q];
    input(arr, q);
    int c[n];
    FOR(i,0,q)
    {
        b[0]=arr[i];
        
        diff(a, b, c, n);
        cout<<solve(c, n)<<endl;
    }

    return 0;
}