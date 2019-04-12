//NOT WORKING FOR HIGHER TEST CASES
#include<bits/stdc++.h>
using namespace std;


long long int findnum(long long int n,set<long long int> s)
{
    auto it=s.begin();
    while(n>*it)
    {
        it++;
    }
    it--;
    auto t1=it;
    it++;
    auto t2=it;
    return min(abs(n-(*t1)),abs(n-(*t2)));

}

int main()
{
    int t;
    cin>>t;
    vector<long long int> v;
    for (long long int i = 1; i <= 1000000000; i=i*2)
    {
        v.push_back(i);
    }
    long long int result;
    set<long long int> s;
    for (long long int i = 0; i < v.size(); ++i)
    {
        for (long long int j = i+1; j < v.size(); ++j)
        {
            result=v[i]+v[j];
            s.insert(result);
        }
    }

    while(t--)
    {
        int n;
        cin>>n;
        if(n==1)

        cout<<findnum(n,s)<<"\n";
    }
    return 0;
}




