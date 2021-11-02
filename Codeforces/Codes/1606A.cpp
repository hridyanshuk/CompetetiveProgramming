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

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        char s[101];
        cin>>s;
        int a=0;
        int b=0;
        int ab=0;
        int ba=0;
        int abindex[100];
        int baindex[100];
        int jab=0, jba=0;
        FOR(i,0,strlen(s))
        {
            if(s[i]=='a')    
            {
                a++;
                if(s[i+1]=='b')
                {
                    ab++;
                    b++;
                    abindex[jab++]=i;
                }
            }
            else if(s[i+1]=='a')
            {
                ba++;
                b++;
                baindex[jba++]=i;
            }
        }
        int diff=0;
        if(ab>ba)
        {
            diff=ab-ba;
            
            if(diff==0)
                break;
            
            
            FOR(i,0,jab)
            {
                if(diff==0)
                {
                    break;
                }
                if(abindex[i]==0)
                {
                    s[0]='b';
                    diff--;
                    continue;
                }
                
                else if(s[abindex[i]-1]!='b' && s[abindex[i]+2]!='a')
                {
                    s[abindex[i]]='b';
                    diff--;
                }
            }
        }
        
        
        else if(ba>ab)
        {
            diff=ba-ab;
            
            if(diff==0)
                break;
            
            
            FOR(i,0,jba)
            {
                if(diff==0)
                {
                    break;
                }
                if(baindex[i]==0)
                {
                    s[0]='a';
                    diff--;
                    continue;
                }
                
                else if(s[abindex[i]-1]!='a' && s[abindex[i]+2]!='b')
                {
                    s[abindex[i]]='a';
                    diff--;
                }
            }
        }
        if(diff!=0)
        {
            if(ab>ba)
            {
                FOR(i,0,strlen(s))
                {
                    cout<<'a';
                }
                cout<<endl;
            }
            else
            {
                FOR(i,0,strlen(s))
                {
                    cout<<'b';
                }
                cout<<endl;
            }
        }
        else
            cout<<s<<endl;
    }

    return 0;
}