#include <bits/stdc++.h>
using namespace std;

int findWays(int v1, vector<vector<int>> adjList, int V)
{
    int count = 1;
    for (int i = 0; i < adjList[v1].size(); i++)
    {
        count += findWays(adjList[v1][i], adjList, V);
    }
    return count;
}

int main()
{
    int V;
    int E;
    cin >> V >> E;
    vector<vector<int>> adjList;
    for (int i = 0; i < V; i++)
    {
        vector<int> v;
        adjList.push_back(v);
    }

    for (int i = 0; i < E; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        adjList[v1].push_back(v2);
    }
    int count = 0;
    int s;
    cin >> s;
    // for (int i = 0; i < V; i++)

    count += findWays(s, adjList, V);

    cout << count;
    return 0;
}