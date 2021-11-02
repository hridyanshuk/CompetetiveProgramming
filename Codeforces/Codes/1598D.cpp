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
int fact(int n);
 
int nCr(int n, int r)
{
    return fact(n) / (fact(r) * fact(n - r));
}
 
int fact(int n)
{
    int s = 1;
    for (int i = 2; i <= n; i++)
        s = s * i;
    return s;
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
        int arr[n][2];
        int m1=0, m2=0;
        FOR(i,0,n)
        {
            cin>>arr[i][0];
            cin>>arr[i][1];
            if(m1<arr[i][0])
            {
                m1=arr[i][0];
            }
            if(m2<arr[i][1])
            {
                m2=arr[i][1];
            }
        }
        
        int g1[m1+1]={0};
        int g2[m2+1]={0};
        
        int n1=0;
        int n2=0;
        for(int i=0 ; i<n ; i++)
        {
            g1[arr[i][0]]+=1;
            if(g1[arr[i][0]]==1)
                n1++;
            g2[arr[i][1]]+=1;
            if(g2[arr[i][1]]==1)
                n2++;
        }
        
        int n11=1;
        int n21=1;
        for(int i=0 ; i<m1+1 ; i++)
        {
            if(g1[i]>1)
            {
                n11*=g1[i];
                n1--;
            }
        }
        for(int i=0 ; i<m2+1 ; i++)
        {
            if(g2[i]>1)
            {
                n21*=g2[i];
                n2--;
            }
        }
        int count;
        for(int i=0 ; i<n-1 ; i++)
        {
            for(int j=i ; j<n ; j++)
            {
                if(arr[i][0]==arr[j][0] && arr[i][1]==arr[j][1])
                {
                    count++;
                }
            }
        }
        int s1=nCr(n1, 3);
        int s11=(s1-count)*n11;
        //int s2=n2*(n2-1)*(n2-2)/6;
        int s2=nCr(n2, 3);
        int s21=s2*n21;
        
        cout<<s11+s21-count<<endl;
    }

    return 0;
}