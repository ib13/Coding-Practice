#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void addedge(vector<int> v[],int a,int b)
{
    v[a].push_back(b);
    v[b].push_back(a);
}

void DFS(vector<int> v[],int node,int n,int visited[])
{
    cout<<node;
    visited[node]=1;
    for(auto x:v[node])
    {
        if(visited[x]==0)
        {
            DFS(v,x,n,visited);
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
    int n,i;
    cout<<"Enter number of nodes: ";
    cin>>n;
//    cout<<"Enter starting node: ";
//    cin>>i;
    int visited[n]={0};
    vector<int> v[n];
    addedge(v,0,1);
    addedge(v,1,3);
    addedge(v,1,2);
    addedge(v,2,3);
    addedge(v,3,4);
    addedge(v,0,5);
    addedge(v,0,6);
    print_list(v,n);
    cout<<"\nDFS for the graph is: ";
    for(i=0;i<n;i++)
    {
        if(visited[i]==0)
            DFS(v,i,n,visited);
    }

    return 0;
}
