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
        int n;
        cin>>n;
        int tree[n];
        int perm[n];
        input(tree, n);
        input(perm, n);
        int wt[n];
        int root;
        FOR(i,0,n)
        {
            if(tree[i]==i+1)
            {
                root=i;
                break;
            }
        }
        //wt[root]=0;
        bool stat=true;
        FOR(i,0,n)
        {
            
            int j=tree[i];
            int w=0;
            while(perm[j-1]!=j)
            {
                w++;
                j=perm[j-1];
                if(w>n-1)
                {
                    stat=false;
                    break;
                }
            }
            wt[i]=w;
        }
        if(stat)
            output(wt, n);
        else
        {
            cout<<-1<<endl;
        }
    }

    return 0;
}