#include <bits/stdc++.h>
using namespace std;

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
        int result[n]={0};
        int min_jumps[n];
        min_jumps[0]=0;
        for(int i=1;i<n;i++)
            min_jumps[i]=1000;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(A[j]>=i-j)
                {
                    if(min_jumps[i]>min_jumps[j]+1)
                    {
                        min_jumps[i]=min_jumps[j]+1;
                        result[i]=j;
                    }

                }
            }
        }
        if(min_jumps[n-1]==1000)
            cout<<-1<<endl;
        else
            cout<<min_jumps[n-1]<<endl;

    }
    return 0;
}

