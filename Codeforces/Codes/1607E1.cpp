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
        int n, m;
        cin>>n>>m;
        char s[1000001];
        cin>>s;
        int hor=0;
        int ver=0;
        int maxH=0, minH=0;
        int maxV=0, minV=0;
        int x, y;
        int len=strlen(s);
        bool statH=true;
        bool statV=true;
        FOR(i,0,len)
        {
            if(s[i]=='L' && statH)
            {
                hor--;
                if(hor<minH)
                {
                    if(maxH-hor >= m-1)
                    {
                        statH=false;
                    }
                    
                    else
                    {
                        minH=hor;
                    }
                    
                }
            }
            else if(s[i]=='R' && statH)
            {
                hor++;
                if (hor>maxH)
                {
                    if(hor-minH > m-1)
                    {
                        statH=false;
                    }
                    
                    else
                    {
                        maxH=hor;
                    }
                    
                }
            }
            if(s[i]=='D' && statV)
            {
                
                ver--;
                //cout<<ver<<endl;
                if(ver<minV)
                {
                    if(maxV-ver >= n-1)
                    {
                        statV=false;
                    }
                    else
                    {
                        minV=ver;
                    }
                    
                }
                //cout<<maxV<<" "<<minV<<"\n";

            }
            else if(s[i]=='U' && statV)
            {
                ver++;
                //cout<<ver<<endl;
                if (ver>maxV)
                {
                    if(ver-minV > n-1)
                    {
                        statV=false;
                    }
                    else
                    {
                        maxV=ver;
                    }
                }
                //cout<<maxV<<" "<<minV<<"\n";

            }

            if(statV==false && statH==false)
            {
                break;
            }
        }
        if(minH<0)
            y=1-minH;//-maxH;
        else
            y=m-maxH;
        if(minV<0)
            x=1-minV;//-maxH;
        else
            x=n-maxV;
        
        //cout<<maxV<<" "<<minV<<"\n";
        //cout<<maxH<<" "<<minH<<"\n";
        cout<<x<<" "<<y<<endl;
    }

    return 0;
}