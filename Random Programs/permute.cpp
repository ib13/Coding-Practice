#include<bits/stdc++.h>
using namespace std;
void permute(string &s,int count[],int level, vector<char> result,set<vector<char> > &per)
{
    if (level==s.length())
    {
        per.insert(result);
        return;
    }
    for(int i=0;i<s.length();i++)
    {
        if(count[i]==0)
            continue;
        else
        {
            count[i]=0;
            result[level]=s[i];
            permute(s,count,level+1,result,per);
            count[i]=1;
        }
    }
}
int main()
{
    string s;
    cin>>s;
    set<vector<char> > per;
    vector<char> result(s.length());
    int count[s.length()];
    for(int i=0;i<s.length();i++)
        count[i]=1;
    permute(s,count,0,result,per);
    set<vector<char> > ::iterator it;
    for(it=per.begin();it!=per.end();it++)
    {
        vector<char> v=*it;
        for(int i=0;i<v.size();i++)
            cout<<v[i];
        cout<<"\n";
    }
//    cout<<per.size();
    return 0;
}

