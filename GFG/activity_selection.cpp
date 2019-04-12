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
        vector<int> start(n);
        vector<int> end(n);
        for(int i=0;i<n;i++)
            cin>>start[i];
        for(int i=0;i<n;i++)
            cin>>end[i];
        vector<pair<pair<int,int>,int> > v;
        for(int i=0;i<n;i++)
            v.push_back(make_pair(make_pair(end[i],start[i]),i));
        sort(v.begin(),v.end());
        auto it1=v.begin();
        int count=1;
        for(auto it2=v.begin()+1;it2!=v.end();it2++)
        {
            if(it2->first.second>=it1->first.first)
            {
                count++;
                it1=it2;
            }

        }
        cout<<count<<endl;
    }
    return 0;
}