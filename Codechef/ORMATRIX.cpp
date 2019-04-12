#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;

        int A[n][m];
        string s[n];
        for (int i = 0; i < n; ++i)
        {
            cin>>s[i];
        }
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if(s[i][j]=='1')
                    A[i][j]=1;
                else
                    A[i][j]=0;
            }
        }
        int count=0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if(A[i][j]==0)
                    count++;
            }
        }
        if(count==n*m)
        {
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < m; ++j)
                {
                    cout<<-1<<" ";
                }
                cout<<"\n";
            }
        }
        else
        {
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < m; ++j)
                {
                    int flag=0;
                    if(A[i][j]==1)
                        cout<<"0"<<" ";
                    else
                    {
                        for (int k = 0; k < n; ++k)
                        {
                            if(A[k][j]==1)
                                flag=1;
                        }
                        for (int k = 0; k < m; ++k)
                        {
                            if(A[i][k]==1)
                                flag=1;
                        }
                        if(flag==1)
                        {
                            cout<<1<<" ";
                        }
                        else
                        {
                            cout<<2<<" ";
                        }
                    }
                }
                cout<<"\n";
            }
        }
    }
    return 0;
}

