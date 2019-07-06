#include <iostream>
using namespace std;
#include <vector>
void findPath(int **adjacencyMatrix, int V, int sv, int ev, int visited[], vector<int> &v)
{
    visited[sv] = 1;
    v.push_back(sv);
    if (sv == ev)
    {
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[v.size() - i - 1] << " ";
        }
        return;
    }
    for (int i = 0; i < V; i++)
    {
        if (adjacencyMatrix[i][sv] == 1 && visited[i] == 0)
        {

            findPath(adjacencyMatrix, V, i, ev, visited, v);
        }
    }
    v.pop_back();
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
