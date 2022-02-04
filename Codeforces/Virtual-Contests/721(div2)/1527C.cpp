#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        
        int arr[n];
        for (int i = 0 ; i < n; i++)
        {
            cin>>arr[i];
        }

        map <long long, long long> m;

        long long dp[n]={0};
        long long ans=0;

        for(int i=0 ; i<n ; i++)
        {
            if(i)
            {
                dp[i]=dp[i-1];
            }
            if(m.count(arr[i]))
            {
                dp[i]+=m[arr[i]];
                m[arr[i]]+=i+1;
            }
            else
            {
                m[arr[i]]=i+1;
            }
            ans+=dp[i];
        }
        cout<<ans<<endl;
        
    }
}