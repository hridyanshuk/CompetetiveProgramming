#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
using namespace std;

typedef long long ll;

#define FOR(i,m,n) for(int i=m ; i<n ; i++)

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
        cout<<arr[i];
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        char arr[n+1];
        cin>>arr;
        int a=0, b=0;
        int an[n]={0};
        int bn[b]={0};
        FOR(i,0,n)
        {
            if(arr[i]=='a')
                {
                    a++;
                    an[i]=1;
                }
            else
            {
                b++;
                bn[i]=1;
            }
        }
        if(a==0 || b==0)
        {
            cout<<-1<<" "<<-1<<endl;
        }
        else if(a==b)
        {
            cout<<1<<" "<<n<<endl;
        }
        else
        {
            int l=0, r=n-1;
            int diff=abs(a-b);
            char more='b';
            if(a>b)
                more='a';
            int k=0;
            while(arr[l]==more)
            {
                l++;
                diff--;
                if(diff==0)
                {
                    break;
                }
            }
            if(diff>0)
            {
                while(arr[r]==more)
                {
                    r--;
                    diff--;
                    if(diff==0)
                    {
                        break;
                    }
                }
                if(diff>0)
                {
                    int d=0;
                    int i;
                    FOR(i,l,r+1)
                    {
                        if(arr[i]!=more)
                        {
                            d++;
                        }
                        else
                        {
                            d--;
                        }
                        if(d==0)
                        {
                            r=i;
                            break;
                        }
                    }
                }
            }
            cout<<l+1<<" "<<r+1<<endl;
        }
    }

    return 0;
}