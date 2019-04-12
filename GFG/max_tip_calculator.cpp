// https://practice.geeksforgeeks.org/problems/maximum-tip-calculator/0
// Unsolved
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int  main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x,y;
        cin>>n>>x>>y;
        int A[n];
        int B[n];
        for (int i = 0; i < n; ++i)
        {
            cin>>A[i];
        }
        for (int i = 0; i < n; ++i)
        {
            cin>>B[i];
        }
        vector<pair<int,int>> A1;
        vector<pair<int,int>> B1;
        for (int i = 0; i < n; ++i)
        {
            A1.push_back(make_pair(A[i],i));
            B1.push_back(make_pair(B[i],i));
        }
        sort(A1.begin(),A1.end());
        reverse(A1.begin(),A1.end());
        sort(B1.begin(),B1.end());
        reverse(B1.begin(),B1.end());
        int A2[x];
        int B2[y];
        for (int i = 0; i < x; ++i) 
        {
            A2[i]=A1[i].second;            
        }
        for (int i = 0; i < y; ++i) 
        {
            B2[i]=B1[i].second;            
        }
        int x_it=x,y_it=y;
        int flag=1;
        while(flag)
        {
            flag=0;
            for (int i = 0; i < x; ++i)
            {
                for (int j = 0; j < y; ++j)
                {
                    if(A2[i]==B2[j])
                    {
                        flag=1;
                        if(A1[x_it+1].first>B1[y_it+1].first)
                        {
                            x_it++;
                            A2[i]=A1[x_it].second;
                        }
                        else
                        {
                            y_it++;
                            B2[i]=B1[y_it].second;
                        }
                        break;
                    }
                }
                if(flag==1)
                    break;
            }
        }
        for (int i = 0; i < x; ++i)
        {
            cout<<A2[i]<<" ";
        }
        cout<<endl;
        for (int i = 0; i < y; ++i)
        {
            cout<<B2[i]<<" ";
        }

    }
    return 0;
}

