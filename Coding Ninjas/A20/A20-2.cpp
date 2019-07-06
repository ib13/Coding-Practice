#include <iostream>
using namespace std;

bool hasPath(int **adjacencyMatrix, int V, int sv, int visited[], int ev)
{
    if (sv == ev)
        return true;
    visited[sv] = 1;
    for (int i = 0; i < V; i++)
    {
        if (adjacencyMatrix[i][sv] == 1 && visited[i] == 0 && hasPath(adjacencyMatrix, V, i, visited, ev))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int V, E;
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
    if (hasPath(adjacencyMatrix, V, v1, visited, v2))
        cout << "true";
    else
        cout << "false";

    return 0;
}
