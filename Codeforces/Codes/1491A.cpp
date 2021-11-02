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
void swap(int *a, int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}

void sort(int *arr, int n)
{
    int max=0, maxIndex=-1;
    for(int i=0 ; i<n ; i++)
    {
        for(int j=i ; j<n ; j++)
        {
            if(max<arr[j])
            {
                max=arr[j];
                maxIndex=j;
            }
        }
        swap(&arr[i], &arr[maxIndex]);
    }
}

int kthLargest(int *arr, int k, int n)
{
    
    sort(arr, k);
    int kth=arr[k-1];
    for(int i=k ; i<n ; i++)
    {
        if(arr[k-1]<arr[i])
        {
            swap(&arr[k-1], &arr[i]);
            kth=arr[i];
        }
    }

    return kth;
}

void copy(int *arrFrom, int *arrTo, int n)
{
    for(int i=0 ; i<n ; i++)
    {
        arrTo[i]=arrFrom[i];
    }
}

int main()
{
    
        int n, q;
        cin>>n>>q;
        int t;
        int arr[n];
        int arr2[n];
        input(arr, n);

        copy(arr, arr2, n);
        for(int i=0 ; i<q ; i++)
        {
            cin>>t;
            if(t==1)
            {
                int x;
                cin>>x;
                arr[x-1]=1-arr[x-1];
                copy(arr, arr2, n);
            }
            else if(t==2)
            {
                int k;
                cin>>k;
                cout<<kthLargest(arr2, k, n)<<endl;
                copy(arr, arr2, n);
            }
        }
    

    return 0;
}