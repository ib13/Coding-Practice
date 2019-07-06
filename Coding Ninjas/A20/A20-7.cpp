#include <iostream>
#include <vector>
using namespace std;

void DFS(int **adjacencyMatrix, int V, int sv, int visited[])
{
    visited[sv] = 1;
    for (int i = 1; i <= V; i++)
    {
        if (adjacencyMatrix[i][sv] == 1 && visited[i] == 0)
            DFS(adjacencyMatrix, V, i, visited);
    }
}

int solve(int n, int m, vector<int> u, vector<int> v)
{
    int V = n;
    int E = m;
    int **adjacencyMatrix = new int *[V + 1];
    for (int i = 0; i <= V; i++)
    {
        adjacencyMatrix[i] = new int[V + 1];
        for (int j = 0; j <= V; j++)
        {
            adjacencyMatrix[i][j] = 0;
        }
    }
    for (int i = 0; i < E; i++)
    {
        adjacencyMatrix[u[i]][v[i]] = 1;
        adjacencyMatrix[v[i]][u[i]] = 1;
    }
    int visited[V + 1] = {0};
    int count = 0;
    for (int i = 1; i <= V; i++)
    {
        if (!visited[i])
        {
            count++;
            DFS(adjacencyMatrix, V, i, visited);
        }
    }
    return count;
}

int main()
{
    int n, m;
    vector<int> u, v;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        u.push_back(x);
    }
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    cout << solve(n, m, u, v) << endl;
}