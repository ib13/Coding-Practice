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
        for (int i = 0; i < n; i++)
        {
            cin>>A[i];
        }
        int sum=0;
        for(int i=0;i<n;i++)
        {
            if(i%2==0)
            {
                if(sum>=k)
                    sum+=A[i];
                else if(sum<=-1*k)
                    sum-=A[i];
                else
                {
                    if(sum>0)
                        sum+=A[i];
                    else
                        sum-=A[i];
                }
            }
            else
            {
                if(sum>=k)
                    sum-=A[i];
                else if(sum<=-1*k)
                    sum+=A[i];
                else
                {
                    if(sum>0)
                        sum-=A[i];
                    else
                        sum+=A[i];
                }
            }
        }
        if(abs(sum)>=k)
            cout<<"1";
        else
            cout<<"2";
        cout<<"\n";
    }
    return 0;
}
