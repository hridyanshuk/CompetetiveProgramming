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

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        char num[13];
        cin>>num;
        int len=strlen(num);
        if((num[len-1]-'0')%2==0)
        {
            cout<<0<<endl;
        }
        else if((num[0]-'0')%2==0)
        {
            cout<<1<<endl;
        }
        else
        {
            bool stat=false;
            FOR(i,0,len)
            {
                if((num[i]-'0')%2==0)
                {
                    stat=true;
                    break;
                }
            }
            if(stat)
            {
                cout<<2<<endl;
            }
            else
            {
                cout<<-1<<endl;
            }
        }

    }

    return 0;
}