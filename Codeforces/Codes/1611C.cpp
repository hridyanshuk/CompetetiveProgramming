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

void insertLeft(int *arr, int i, int n)
{
    FOR(j,1,n)
    {
        arr[j]=arr[j-1];
    }
    arr[0]=i;
}

void insertRight(int *arr, int i, int n, int m)
{
    if(n<m-1)
        arr[n]=i;
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
        int arr1[n];
        int last;
        if(arr[0]>arr[n-1])
            last=0;
        else
            last=n-1;
        arr1[0]=arr[last];
        delFromArr(arr, last, &n);
        int count=0;
        bool stat=true;
        
        for(int i=0 ; i<n/2 ; i++)
        {
            if(arr[i]<arr[n-i-1])
            {
                if(i>0)
                {
                    if(arr[i]>arr[i-1] || arr[i]>arr[n-i] || arr[n-i-1]>arr[i-1] || arr[n-i-1]>arr[n-i])
                        stat=false;
                }
                if(stat)
                {
                    insertLeft(arr1, arr[i], count);
                    count++;
                    arr1[count+1]=arr[n-i-1];
                    count++;
                    
                }
            }
            else
            {
                stat=false;
                break;
            }
            if(stat==false)
            {
                break;
            }
        }
        if(count<n)
        {
            if(arr[n/2]>arr1[0])
            {
                arr1[n-1]=arr[n/2];
            }
            else
            {
                insertLeft(arr1, arr[n/2], count);
            }
        }
        if(stat)
        {
            output(arr1, n+1);
        }
        else
        {
            cout<<-1<<endl;
        }

    }

    return 0;
}