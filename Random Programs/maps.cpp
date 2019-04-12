#include<bits/stdc++.h>
using namespace std;
int main()
{
    map<string,int> s;
    s["a"]++;
    auto x=s.begin();
    x=s.find("a");
    cout<<s["v"];
    cout<<x->second;
}
