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
        char c;
        cin>>c;
        char arr[n+1];
        cin>>arr;
        int count=0;
        int index[n];
        int in=-1;
        for(int i=0 ; i<n ; i++)
        {
            if(arr[i]!=c)
            {
                index[count]=i+1;
                count++;
            }
        }
        if(count>0)
        {
            if(count==1 && arr[n-1]!=c)
            {
                cout<<1<<endl<<n-1<<endl;
            }
            else if(count==1 && arr[n-1]==c)
            {
                cout<<1<<endl<<n<<endl;
            }
            else
            {
                FOR(i,1,n)
                {
                    in=i+1;
                    FOR(j,0,count)
                    {
                        if(in%index[j]==0)
                        {
                            in=-1;
                            break;
                        }
                    }
                    if(in!=-1)
                    {
                        break;
                    }
                }
                if(in==-1)
                {
                    if(arr[n-1]!=c)
                    {
                        cout<<2<<endl<<n<<" "<<n-1<<endl;
                    }
                    else
                    {
                        cout<<1<<endl<<n<<endl;
                    }
                }
                else
                {
                    cout<<1<<endl<<in<<endl;
                }
            }
        }
        else
        {
            cout<<0<<endl;
        }
    }

    return 0;
}