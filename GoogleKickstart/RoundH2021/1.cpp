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
    FOR(k,0,t)
    {
        char s[100001];
        char f[27];
        cin>>s;cin>>f;
        int count[26]={0};
        /*FOR(i,0,strlen(s))
        {
            count[s[i]-'a']=count[s[i]-'a']+1;
        }
        int min=0;
        
        FOR(i,0,26)
        {
            if(count[i]>0)
            {
                int m=26;
                FOR(j,0,strlen(f))
                {
                    m=MIN(m,abs(i-(f[j]-'a')));
                }
                min+=m*count[i];
            }
        }*/
        int n=strlen(s);
        int fn=strlen(f);
        int min=0;
        FOR(i,0,n)
        {
            int m=27;
            FOR(j,0,fn)
            {
                m=MIN(abs(s[i]-f[j]), m);
            }
            min+=m;
        }

        cout<<"Case #"<<k+1<<": "<<min<<endl;
    }

    return 0;
}