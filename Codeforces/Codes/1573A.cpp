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
    int t;
    cin>>t;
    while(t--)
    {
        int num;
        cin>>num;
        char arr[num+1];
        scanf("%s", arr);
        int count=0;
        for(int i=0 ; i<num-1 ; i++)
        {
            count+=arr[i]-'0';
            if(arr[i]-'0' > 0)
                count++;
        }
        count=count+(arr[num-1]-'0');
        cout<<count<<endl;
        
    }

    return 0;
}