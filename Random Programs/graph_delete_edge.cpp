#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void addedge(vector<int> v[],int a,int b)
{
    v[a].push_back(b);
    v[b].push_back(a);
}

void deleteedge(vector<int> v[],int a,int b)
{
    int i=0;
    for(auto x:v[a])
    {
        if(x==b)
            v[a].erase(v[a].begin()+i);
        i++;
    }
    i=0;
    for(auto x:v[b])
    {
        if(x==a)
            v[b].erase(v[b].begin()+i);
        i++;
    }
}

void print_list(vector<int> v[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout << "\n Adjacency list of vertex "<< i << "\n head ";
        for(auto x:v[i])
        {
            cout<<"->"<<x;
        }
    }
}


int main()
{
    int n;
    cout<<"Enter number of nodes: ";
    cin>>n;
    vector<int> v[n];
    addedge(v,0,1);
    addedge(v,1,3);
    addedge(v,1,2);
    addedge(v,2,3);
    print_list(v,n);
    deleteedge(v,0,1);
    print_list(v,n);

    return 0;
}
