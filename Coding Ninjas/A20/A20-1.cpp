#include <iostream>
using namespace std;
#include <queue>

void printBFS(int **adjacencyMatrix, int V, int sv, int visited[])
{
    queue<int> q;
    q.push(sv);
    while (!q.empty())
    {
        int vertex = q.front();
        if (visited[vertex] == 0)
        {
            cout << vertex << " ";
            visited[vertex] = 1;
        }
        q.pop();
        for (int i = 0; i < V; i++)
        {
            if (adjacencyMatrix[i][vertex] == 1 && visited[i] == 0)
            {
                q.push(i);
            }
        }
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
        int v1, v2;
        cin >> v1 >> v2;
        adjacencyMatrix[v1][v2] = 1;
        adjacencyMatrix[v2][v1] = 1;
    }

    int visited[V] = {0};
    printBFS(adjacencyMatrix, V, 0, visited);

    return 0;
}
