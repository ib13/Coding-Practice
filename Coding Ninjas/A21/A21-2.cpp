#include <iostream>
#include <limits.h>
using namespace std;

void solve(int **adjacencyMatrix, int V, int E)
{
    bool visited[V] = {false};
    int weights[V];
    int parent[V];

    for (int i = 0; i < V; i++)
    {
        weights[i] = INT_MAX;
        parent[i] = -1;
    }

    weights[0] = 0;

    for (int i = 0; i < V; i++)
    {
        int minindex = 0;
        int minweight = INT_MAX;
        for (int j = 0; j < V; j++)
        {
            if (weights[j] < minweight && !visited[j])
            {
                minweight = weights[j];
                minindex = j;
            }
        }
        visited[minindex] = 1;
        for (int j = 0; j < V; j++)
        {
            if (adjacencyMatrix[minindex][j] > 0 && !visited[j])
            {
                if (weights[j] > adjacencyMatrix[minindex][j])
                {
                    weights[j] = adjacencyMatrix[minindex][j];
                    parent[j] = minindex;
                }
            }
        }
    }
    for (int i = 1; i < V; i++)
    {
        cout << min(i, parent[i]) << " " << max(i, parent[i]) << " " << weights[i] << endl;
    }
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
        int v1;
        int v2;
        int weight;
        cin >> v1 >> v2 >> weight;
        adjacencyMatrix[v1][v2] = weight;
        adjacencyMatrix[v2][v1] = weight;
    }

    solve(adjacencyMatrix, V, E);

    return 0;
}
