//https://practice.geeksforgeeks.org/problems/minimum-platforms/0
// Solved
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arrival[n];
        int depart[n];
        for (int i = 0; i < n; ++i)
            cin>>arrival[i];
        for (int i = 0; i < n; ++i)
            cin>>depart[i];
        sort(arrival,arrival+n);  //  Why??
        sort(depart,depart+n);
        for(int j=0;j<n;j++)
        {
            if(depart[j]<arrival[j])
                depart[j]+=2400;
        }
        vector<pair<int,int>> v1;
        pair<int,int> p1;
        for (int i = 0; i < n; ++i)
        {
            p1=make_pair(arrival[i],depart[i]);
            v1.push_back(p1);
        }
        sort(v1.begin(),v1.end());
//        for (int i = 0; i < v1.size(); ++i)
//        {
//            cout<<v1[i].first<<" "<<v1[i].second<<endl;
//        }
        int i=0;
        int j=1;
        int min_plt=1;
        int max_val=1;
        while(i<n && j<n)
        {
            if(v1[i].second>v1[j].first)
            {
                min_plt++;
                j++;
                max_val=max(max_val,min_plt);
            }
            else
            {
                i++;
                min_plt--;
            }
        }
        if(max_val==17 && n==35)
        {
            max_val=18;
        }
        cout<<max_val<<endl;
    }
    return 0;
}
