#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include <stdio.h>
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
        cout<<arr[i]<<" ";
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
        char arr[n+1];
        cin>>arr;
        int mat[n][n]={0};
        int wins[n]={0};
        bool status=true;
        
        FOR(i,0,n)
        {
            FOR(j,0,n)
                mat[i][j]=0;
        }
        for(int i=0 ; i<n ; i++)
        {
            if(arr[i]=='2')
            {
                FOR(j,0,n)
                {
                    if(arr[j]=='2' && mat[i][j]==0 && i!=j)
                    {
                        mat[i][j]+=1;
                        mat[j][i]-=1;
                        wins[i]++;
                        break;
                    }
                }
            }
        }
        
        
        for(int i=0 ; i<n ; i++)
        {
            if(arr[i]=='2' && wins[i]==0)
            {
                status=false;
                break;
            }
        }


        if(status)
        {
            cout<<"YES\n";
            FOR(i,0,n)
            {
                FOR(j,0,n)
                {
                    if(i==j)
                        printf("X");
                    else if(mat[i][j]==0)
                        printf("=");
                    else if(mat[i][j]>0)
                        printf("+");
                    else
                        printf("-");
                }
                cout<<endl;
            }
        }
        else
        {
            cout<<"NO\n";
        }

    }

    return 0;
}