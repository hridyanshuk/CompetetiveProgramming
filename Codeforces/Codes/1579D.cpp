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

void input(int *arr, int n, int *sum)
{
    FOR(i,0,n)
    {
        cin>>arr[i];
        *sum+=arr[i];
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
        int arr[n];
        int sum=0;
        input(arr,n, &sum);
        sum=sum/n;
        int min=arr[0], max1=-1, max2;;
        int minIndex=0, maxIndex1, maxIndex2;
        int count=0;
        vector <vector<int>> v;
        for(int j=0 ; j<n ; j++)
        {
            
            max1=-1;
            for(int i=0 ; i<n ; i++)
            {
                if(arr[i]>0)
                {
                    count++;
                }
                if(max1<arr[i])
                {
                    max1=arr[i];
                    maxIndex1=i;
                }
            }
            if(count<=1)
            {
                break;
            }
            max2=-1;
            for(int i=0 ; i<n ; i++)
            {
                if(max2<arr[i] && i!=maxIndex1)
                {
                    max2=arr[i];
                    maxIndex2=i;
                }
            }
            count=0;
            arr[maxIndex2]=-1;
            arr[maxIndex1]-=1;
            v.push_back({maxIndex1, maxIndex2});
        }
        cout<<v.size()<<endl;
        for(auto i=0 ; i<v.size() ; i++)
        {
            cout<<v[i][0]+1<<" "<<v[i][1]+1<<endl;
        }

    }

    return 0;
}