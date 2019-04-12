#include<bits/stdc++.h>
using namespace std;

bool anagram(string s1,string s2)
{
    if(s1.length()!=s2.length())
        return false;
    int l=s1.length();
    map<char,int> m1,m2;
    for(int i=0;i<l;i++)
    {
        m1[s1[i]]++;
        m2[s2[i]]++;
    }
    auto x1=m1.begin();
    auto x2=m2.begin();
    while(x1!=m1.end())
    {
        if(x1->second!=x2->second)
            return false;
        x1++;
        x2++;
    }
    return true;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s1,s2;
        cin>>s1>>s2;
        if(anagram(s1,s2))
            cout<<"YES";
        else
            cout<<"NO";
        cout<<"\n";
    }
}

