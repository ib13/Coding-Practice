#include <bits/stdc++.h>
using namespace std;
void isConnected(int **adjacencyMatrix, int V, int sv, int visited[])
{
    visited[sv] = 1;
    for (int i = 0; i < V; i++)
    {
        if (adjacencyMatrix[i][sv] == 1 && visited[i] == 0)
            isConnected(adjacencyMatrix, V, i, visited);
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
    int v1, v2;
    cin >> v1 >> v2;
    int visited[V] = {0};
    vector<int> v;
    isConnected(adjacencyMatrix, V, 0, visited);
    for (int i = 0; i < V; i++)
    {
        if (visited[i] == 0)
        {
            cout << "false";
            return 0;
        }
    }
    cout << "true";

    return 0;
}
