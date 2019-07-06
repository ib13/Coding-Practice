#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#include <unordered_map>
void findPath(int **adjacencyMatrix, int V, int sv, int ev, int visited[], vector<int> &v)
{
    int m[V];
    for (int i = 0; i < V; i++)
    {
        m[i] = -1;
    }

    queue<int> q;
    q.push(sv);
    while (!q.empty())
    {
        int vertex = q.front();
        if (vertex == ev)
        {
            cout << ev << " ";
            while (ev != sv)
            {
                cout << m[ev] << " ";
                ev = m[ev];
            }
            return;
        }
        visited[vertex] = 1;
        q.pop();
        for (int i = 0; i < V; i++)
        {
            if (adjacencyMatrix[i][vertex] == 1 && visited[i] == 0)
            {
                if (m[i] == -1)
                    m[i] = vertex; //we use this to know who added i
                q.push(i);
            }
        }
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
    findPath(adjacencyMatrix, V, v1, v2, visited, v);

    return 0;
}
