//Problem 1574 A
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
        char o='(';
        char c=')';
        char arr[2*n+1];
        arr[2*n]='\0';
        for(int i=0 ; i<n ; i++)
        {
            int j;
            for(j=0 ; j<n-i ; j++)
            {
                arr[j]=o;
            }
            for(int k=0 ; k<i ; k++)
            {
                arr[j]=c;
                arr[j+1]=o;
                j+=2;
            }
            for(int k=0 ; k<n-i ; k++)
            {
                arr[j]=c;
                j++;
            }
            cout<<arr<<endl;
        }

    }
    return 0;
}
