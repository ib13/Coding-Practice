#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int i=0;
    vector<int> v[4];
    v[0].push_back(1);
    v[0].push_back(2);
    v[0].push_back(3);
    v[0].push_back(4);
    for(auto x:v[0])
    {
        if(x==3)
        {
            v[0].erase(v[0].begin()+i);
        }
        i++;
    }
    for(auto x:v[0])
    {
        cout<<x;
    }
    return 0;
}

