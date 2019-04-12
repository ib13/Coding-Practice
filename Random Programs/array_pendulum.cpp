#include<bits/stdc++.h>
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
        multiset<int> s;
        s.clear();
        for(int i=0;i<n;i++)
        {
            cin>>A[i];
            s.insert(A[i]);
        }
        int i1,i2;
        i1=i2=(n-1)/2;
        i2++;
        bool flag=true;
        auto x=s.begin();
        while(i1>=0 || i2<=n-1)
        {
                A[i1]=*x;
                i1--;
                x++;
                A[i2]=*x;
                i2++;
                x++;
        }
//        for(auto it=s.begin();it!=s.end();it++)
//        {
//            cout<<*it;
//        }
        for(int i=0;i<n;i++)
            cout<<A[i]<<" ";
        cout<<endl;
    }
}
