#include <bits/stdc++.h>
using namespace std;

void printDFS(int **adjacencyMatrix, int V, int sv, int visited[], vector<int> &v)
{
    v.push_back(sv);
    visited[sv] = 1;
    for (int i = 0; i < V; i++)
    {
        if (adjacencyMatrix[i][sv] == 1 && visited[i] == 0)
            printDFS(adjacencyMatrix, V, i, visited, v);
    }
}

int main()
{
    int V, E, tempX, tempY;
    cin >> V >> E;
    int **adjacencyMatrix = new int *[V];
    for (int i = 0; i < V; i++)
    {
        adjacencyMatrix[i] = new int[V];
        for (int j = 0; j < V; j++)
        {
            adjacencyMatrix[i][j] = 0;
        }
    }
    for (int i = 0; i < E; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        adjacencyMatrix[v1][v2] = 1;
        adjacencyMatrix[v2][v1] = 1;
    }
    int visited[V] = {0};
    vector<int> v;
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            printDFS(adjacencyMatrix, V, i, visited, v);
            sort(v.begin(), v.end());
            for (int i = 0; i < v.size(); i++)
            {
                cout << v[i] << " ";
            }
            v.clear();
            cout << endl;
        }
    }
    return 0;
}
