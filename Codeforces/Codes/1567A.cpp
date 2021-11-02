//Problem 1567A

#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    int n;//width
    while(t--)
    {
        cin>>n;
        char arr[n];
        cin>>arr;
        for(int i=0 ; i<n ; i++)
        {
            if(arr[i]=='L' || arr[i]=='R')
                cout<<arr[i];
            else if(arr[i]=='U')
                cout<<"D";
            else if(arr[i]=='D')
                cout<<"U";
        }
        cout<<endl;
    }
    return 0;
}
