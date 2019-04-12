#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int A1[n];
        int A2[m];
        for(int i=0;i<n;i++)
            cin>>A1[i];
        for(int i=0;i<m;i++)
            cin>>A2[i];
        map<int,int> map1;
        for(int i=0;i<m;i++)
        {
            map1[A2[i]]=1;
        }
        for(int i=0;i<n;i++)
        {
            if(map1[A1[i]]!=0)
            {
                map1[A1[i]]++;
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<map1[A2[i]]-1;j++)
            {
                cout<<A2[i]<<" ";
            }
        }
        multiset<int> set1;
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(map1[A1[i]]==0)
            {
                set1.insert(A1[i]);
                count++;
            }
        }
        for (auto it = set1.begin(); it != set1.end(); it++)
            cout << *it << " ";
        cout<<endl;
    }
}