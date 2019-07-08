#include <iostream>
#include <limits.h>
using namespace std;

void solve(int **adjacencyMatrix, int V, int E)
{
    bool visited[V] = {false};
    int distance[V];
    for (int i = 0; i < V; i++)
        distance[i] = INT_MAX;
    distance[0] = 0;
    for (int i = 0; i < V; i++)
    {
        int minindex = 0;
        int mindist = INT_MAX;
        for (int j = 0; j < V; j++)
        {
            if (distance[j] < mindist && !visited[j])
            {
                mindist = distance[j];
                minindex = j;
            }
        }
        visited[minindex] = 1;
        for (int j = 0; j < V; j++)
        {
            if (adjacencyMatrix[minindex][j] > 0 && !visited[j])
            {
                distance[j] = min(distance[j], distance[minindex] + adjacencyMatrix[minindex][j]);
            }
        }
    }
    for (int i = 0; i < V; i++)
    {
        cout << i << " " << distance[i] << endl;
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
