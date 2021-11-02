#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
using namespace std;

typedef long long ll;

#define FOR(i,m,n) for(int i=m ; i<n ; i++)
#define XOR(a,b) ((a)|(b))-((a)&(b))

const ll MOD_N=1000000007;


void insertionSort(int *arr, int n, int start, int seq)
{
    for(int i=start+seq ; i<n ; i=i+seq)
    {
        int t=arr[i];
        for(int j=i-seq ; j>=start ; j=j-seq)
        {
            if(t>arr[j])
            {
                break;
            }
            else
            {
                arr[j+seq]=arr[j];
                arr[j]=t;
            }
        }
    }
}
int calc(int i, int p)
{
    return (int)pow(2,p-i)-1;
}
void shellSort(int *arr, int n)
{
    int p=log(n)/log(2);
    for(int i=0 ; i<p ; i++)
    {
        int seq=calc(i,p);
        for(int j=0 ; j<seq ; j++)
        {
            insertionSort(arr, n, j, seq);
        }
    }
}


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
void del(int *arr, int i, int *n)
{
    FOR(j,i,*n-1)
    {
        arr[j]=arr[j+1];
    }
    *n=*n-1;
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
        FOR(i,0,n)
        {
            cin>>arr[i];
        }
        shellSort(arr, n);
        int max=arr[0];
        int ntemp=n;
        FOR(i,1,n)
        {
            if((arr[i]-arr[i-1])>=max)
            {
                max=arr[i]-arr[i-1];
            }
        }
        cout<<max<<endl;
    }

    return 0;
}




