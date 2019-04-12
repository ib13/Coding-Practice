#include<bits/stdc++.h>
using namespace std;

int LCM(int n,int m)
{
    for(int i=1;i<=(n*m);i++)
    {
        if(i%n==0 && i%m==0)
            return i;
    }
}

int GCD(int n,int m)
{
    int t=1;
    for(int i=1;i<=min(n,m);i++)
    {
        if(n%i==0 && m%i==0)
            t=i;
    }
    return t;
}

int main()
{
    int n,m;
    cin>>n>>m;
    cout<<LCM(n,m)<<"\n"<<GCD(n,m);
    return 0;
}
