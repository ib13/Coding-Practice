#include <bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.
int main()
{

    int t;
    cin >> t;

    while (t--)
    {

        int v, e;
        cin >> v >> e;

        vector<int> adj[v];

        for (int i = 0; i < e; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        cout << isCyclic(v, adj) << endl;
    }

    return 0;
}
/*This is a function problem.You only need to complete the function given below*/
/*  Function to check if the given graph contains cycle
*   V: number of vertices
*   adj[]: representation of graph
*/
bool isCyclicHelper(int V, vector<int> adj[], bool visited[], bool recStack[])
{
    visited[V] = 1;
    recStack[V] = 1;
    for (int i = 0; i < adj[V].size(); i++)
    {
        if (!visited[i] && isCyclicHelper(i, adj, visited, recStack) == 1)
            return 1;
        else if (recStack[i] == 1)
            return 1;
    }
    recStack[V] = 0;
    return false;
}

bool isCyclic(int V, vector<int> adj[])
{
    bool visited[V] = {0};
    bool recStack[V] = {0};
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            if (isCyclicHelper(i, adj, visited, recStack) == 1)
                return 1;
        }
    }
    return 0;
}
