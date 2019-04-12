#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    map<int,string> s;
    vector<pair<int,int> > v;
    vector<pair<int,pair<int,int> > > v1;
//    v1.emplace_back(3,4,6);
    v1.emplace_back(3,make_pair(4,6));
    v.emplace_back(3,5);
    v.emplace_back(4,7);
    v.emplace_back(3,6);
    s.emplace(3,"Hi");
    s.emplace(6,"Hello");
    for(auto x:v)
    {
        cout<<x.first<<" "<<x.second<<"\n";
    }
    for(auto x:s)
    {
        cout<<x.first<<" "<<x.second<<"\n";
    }
    return 0;
}
