#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void addedge(vector<int> v[],int a,int b)
{
    v[a].push_back(b);
    v[b].push_back(a);
}

void DFS(vector<int> v[],int node,int n)
{
    int visited[n]={0};
    stack<int> s;
    s.push(node);
    node=s.top();
    cout<<node;
    visited[node]=1;
    s.pop();
    while(true)
    {
        for(auto x:v[node])
        {
            if(visited[x]==0)
            {
                visited[x]=1;
                s.push(x);
            }
        }
        if(s.empty())
        {
            break;
        } else{
            node=s.top();
            cout<<node;
            s.pop();
        }
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
//    print_list(v,n);
    DFS(v,3,n);
    return 0;
}
