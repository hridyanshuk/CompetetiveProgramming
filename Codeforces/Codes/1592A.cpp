#include <iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        int h;
        cin>>h;
        int arr[n];
        int max1=0;
        int maxIndex=0;
        int max;
        cin>>arr[0];
        max=arr[0];
        for(int i=1 ; i<n ; i++)
        {
            cin>>arr[i];
            if(max<arr[i])
            {
                max=arr[i];
                maxIndex=i;
            }
        }
        if(maxIndex==0)
        {
            max1=arr[1];
        }
        else
            max1=arr[0];

        for(int i=0 ; i<n ; i++)
        {
            if(i!=maxIndex && arr[i]>max1)
                max1=arr[i];            
        }
        int sum=0;

        if(h<=max)
        {
            sum=1;
        }
        else
        {
            
        if(h%(max1+max)==0)
            sum=2*(h/(max1+max));
        else
        {
            sum=2*(h/(max1+max));
            if(h%(max1+max) >= max)
                sum+=2;
            else
                sum+=1;
        }
        }       
    
    
        cout<<sum<<endl;
    }

    return 0;
}