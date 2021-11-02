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
        ll n;
        cin>>n;
        int i=0;
        while((n/(ll)pow(10,i))>0)
        {
            i++;
        }
        //cout<<i<<endl;
        ll x=n;
        int arr[i]={0};
        int j=0;
        while(x>0)
        {
            arr[j++]=x%10;
            x=x/10;
        }
        
        int a1=-1, a2=-1;
        int b1=-1, b2=-1;
        for( j=0 ; j<i ; j++ )
        {
            if(a1==-1 && arr[j]==5)
            {
                a1=j;
                //cout<<j<<endl;
            }
            else if(a1!=-1 && (arr[j]==2 || arr[j]==7) && a2==-1)
            {
                a2=j;
                //cout<<j<<endl;
            }
            if(b1==-1 && arr[j]==0)
            {
                b1=j;
            }
            else if(b1!=-1 && (arr[j]==5 || arr[j]==0) && b2==-1)
            {
                //cout<<j<<endl;
                b2=j;
            }
        }
        int a=i, b=i;
        if(a1>=0 && a2>=0)
        {
            a=a2-1;
        }
        if(b1>=0 && b2>=0)
        {
            b=b2-1;
        }
        if(a<b)
        {
            cout<<a<<endl;
        }
        else
        {
            cout<<b<<endl;
        }
        //cout<<a1<<" "<<a2<<" "<<b1<<" "<<b2<<" "<<a<<" "<<b<<endl;
    }

    return 0;
}