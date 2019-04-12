#include<bits/stdc++.h>
using namespace std;
int main()
{
    stack<int> s;
    int n,num;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>num;
        s.push(num);
    }
    int max1=s.top();
    while(!s.empty())
    {
        max1=max(max1,s.top());
        s.pop();
    }
    cout<<max1;
}
