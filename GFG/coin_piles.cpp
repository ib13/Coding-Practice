#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int A[n];
        for(int i=0;i<n;i++)
            cin>>A[i];
        sort(A,A+n);
        int min1=INT_MAX;
        int remove=0;
        for(int i=0;i<n-1;i++)
        {
            int min2=A[i];
            remove=0;
            for(int j=i;j<n;j++)
            {
                if(A[j]>min2+k)
                {
                    remove+=A[j]-min2-k;
                }
            }
            for(int j=0;j<i;j++)
                remove+=A[j];
            min1=min(min1,remove);
        }

        cout<<min1<<"\n";
    }
    return 0;
}

