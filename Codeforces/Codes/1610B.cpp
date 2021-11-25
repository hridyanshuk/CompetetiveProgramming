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

bool palin(int *arr, int n)
{
    FOR(i,0,n/2)
    {
        if(arr[i]!=arr[n-1-i])
        {
            return false;
        }
    }
    return true;
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
        int distinct[10]={0};//3 6 7 4 6 9

        //0 0 0 1 1 0 2 1 0 1
        //0 1 2 3 4 5 6 7 8 9
        int arr1[n];
        if(palin(arr, n))
        {
            YES;
            continue;
        }
        FOR(i,0,n)
        {
            distinct[arr[i]]=distinct[arr[i]]+1;
        }
        bool stat=false;
        FOR(i,0,10)
        {
            if(stat)
                break;
            if(distinct[i]>0)
            {
                
                int c=0;
                FOR(j,0,n)
                {
                    if(arr[j]==i)
                        continue;
                    arr1[c]=arr[j];
                    c++;
                }
                
                if(palin(arr1, c))
                {
                    YES;
                    stat=true;
                }
            }
        }
        if(stat==false)
        {
            NO;
        }
        else
            continue;
    }

    return 0;
}