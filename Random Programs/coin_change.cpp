#include<bits/stdc++.h>
using namespace std;

int change(int A[],int n,int sum)
{
    int V[n+1][sum+1];
    for(int i=0;i<=sum;i++)
    {
        V[0][i]=100;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=sum;j++)
        {
            if(j<A[i-1])
                V[i][j]=V[i-1][j];
            else
            {
                V[i][j]=min(V[i-1][j],1+V[i-1][j-A[i-1]]);
            }
        }
    }
    return V[n][sum];
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++)
            cin>>A[i];
        int sum;
        cin>>sum;
        cout<<change(A,n,sum);
    }
    return 0;
}
