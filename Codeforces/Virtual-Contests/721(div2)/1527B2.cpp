#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
using namespace std;

typedef long long ll;

#define FOR(i,m,n) for(int i=m ; i<n ; i++)
#define XOR(a,b) ((a)|(b))-((a)&(b))
#define YES cout<<"YES\n"
#define NO cout<<"NO\n"

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
    FOR(i,2,r)
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

void delFromArr(int *arr, int i, int *n)
{
    FOR(j,i,*n-1)
    {
        arr[j]=arr[j+1];
    }
    *n=*n-1;
}

int MIN(int a, int b)
{
    if(a<b)
    {
        return a;
    }
    return b;
}

bool pallin(char *s, int n)
{
    FOR(i,0,n/2)
    {
        if(!(s[i]==s[n-i-1]))
            return false;
    }
    return true;
}


// void optimal(char *s, int n, int nof, int *a, int *b, bool alice, bool rev)
// {
//     //printf("intial: \ns=%s\nn=%d, nof=%d, a=%d, b=%d\n", s,n,nof,*a,*b);
//     if(nof==0)
//     {
//         return;
//     }
//     if(alice)
//     {
//         int min=*a,max=*b;
//         int temp_min=min, temp_max=max;
//         int returnMin, returnMax;
//         int diff;
        
        
//         int n0=0;
//         FOR(i,0,n)
//         {
//             if(s[i]=='1')
//                 continue;
//             n0++;
//             s[i]='1';
//             temp_min+=1;
//             optimal(s,n, nof-1, &temp_min,&temp_max, false, false);
//             if(n0==1)
//             {
//                 returnMin=temp_min;
//                 returnMax=temp_max;
//                 diff=returnMax-returnMin;
//             }
//             if(diff<temp_max-temp_min)
//             {
//                 returnMin=temp_min;
//                 returnMax=temp_max;
//             }
//             temp_min=*a;
//             temp_max=*b;
//             s[i]='0';
//         }

//         if(!rev)
//         {
            
//             if(!pallin(s, n))
//             {
//                 //cout<<"rev\n";
//                 char revved_s[n];
//                 strcpy(revved_s, s);
//                 strrev(revved_s);
//                 optimal(revved_s,n,nof,&temp_min, &temp_max, false, true);
//                 if(diff<temp_max-temp_min)
//                 {
//                     returnMin=temp_min;
//                     returnMax=temp_max;
//                 }
//             }
            
//         }

//         *a=returnMin;
//         *b=returnMax;
//     }

//     else
//     {
//         int min=*a,max=*b;
//         int temp_min=min, temp_max=max;
//         int returnMin, returnMax;
//         int diff;
        
        
//         int n0=0;
//         FOR(i,0,n)
//         {
//             if(s[i]=='1')
//                 continue;
//             n0++;
//             s[i]='1';
//             temp_max+=1;
//             optimal(s,n, nof-1, &temp_min,&temp_max, true, false);
//             if(n0==1)
//             {
//                 returnMin=temp_min;
//                 returnMax=temp_max;
//                 diff=returnMax-returnMin;
//             }
//             if(diff>temp_max-temp_min)
//             {
//                 returnMin=temp_min;
//                 returnMax=temp_max;
//             }
//             temp_min=*a;
//             temp_max=*b;
//             s[i]='0';
//         }

//         if(!rev)
//         {
//             if(!pallin(s, n))
//             {
//                 //cout<<"rev\n";
//                 char revved_s[n];
//                 strcpy(revved_s, s);
//                 strrev(revved_s);
//                 optimal(revved_s,n,nof,&temp_min, &temp_max, true, true);
//                 if(diff>temp_max-temp_min)
//                 {
//                     returnMin=temp_min;
//                     returnMax=temp_max;
//                 }
//             }
//         }

//         *a=returnMin;
//         *b=returnMax;
//     }
//     //printf("final: \ns=%s\nn=%d, nof=%d, a=%d, b=%d\n", s,n,nof,*a,*b);
//     return;
// }


// int alice_wins(char *s, int n, int nof)
// {
//     int a=0,b=0;
//     //cout<<"n = "<<n<<" s = "<<s<<" nof = "<<nof<<endl;
//     optimal(s,n,nof,&a, &b, true, false);
//     //cout<<"a : "<<a<<" b : "<<b<<endl;
//     if(a>b)
//         return 2;
//     else if(a==b)
//         return 1;
//     return 0;
// }

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        char s[n+1];
        cin>>s;
        int nof=0;
        int s01=0;
        FOR(i,0,n)
        {
            if(s[i]=='0')
            {
                nof++;
                if(s[i]!=s[n-i-1])
                {
                    s01++;
                }
            }
        }
        
        bool palin=pallin(s,n);
        if(palin)
        {
            if(nof==1)
            {
                cout<<"BOB\n";                
            }
            else if(nof==0)
            {
                cout<<"DRAW\n";
            }
            else if(nof%2==0)
                cout<<"BOB\n";
        
            else
                cout<<"ALICE\n";
        }
        else
        {
            if(nof==2 && s01==1)
                cout<<"DRAW\n";
            else if(nof==1)
            {
                cout<<"BOB\n";
            }
            else
            {
                cout<<"ALICE\n";
            }
        }
    }

    return 0;
}