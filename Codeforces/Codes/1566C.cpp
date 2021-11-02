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
        char arr[2][n+1];
        cin>>arr[0]>>arr[1];
        int sum=0;
        int a, b;
        a=arr[0][0]-'0';
        b=arr[1][0]-'0';
        int a1, b1;
        FOR(i,0,n)
        {
            a1=a;
            b1=b;
            a=arr[0][i]-'0';
            b=arr[1][i]-'0';
            if(a!=b)
            {
                sum+=2;
            }
            else if(a==b && a==0)
            {
                sum+=1;
            }
            else if(a==b && a==1)
            {
                int a2=arr[0][i+1]-'0';
                int b2=arr[1][i+1]-'0';
                if(a1==b1 && a1==0)
                {
                    sum+=1;
                }
                else if(a2==b2  && i+1<n && a2==0)
                {
                    sum+=2;
                    arr[0][i+1]='1';
                    i++;
                }
            }
        }
        cout<<sum<<endl;
    }

    return 0;
}