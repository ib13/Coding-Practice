#include <bits/stdc++.h>
using namespace std;

void printDFS(int **adjacencyMatrix, int V, int sv, int visited[])
{
    cout << sv << " ";
    visited[sv] = 1;
    for (int i = 0; i < V; i++)
    {
        if (adjacencyMatrix[i][sv] == 1 && visited[i] == 0)
            printDFS(adjacencyMatrix, V, i, visited);
    }
}

int main()
{
    int V;
    int E;
    cin >> V;
    cin >> E;
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
    printDFS(adjacencyMatrix, V, 0, visited);
    return 0;
}

// 5 6 0 1 0 2 1 3 3 2 3 4 2 4