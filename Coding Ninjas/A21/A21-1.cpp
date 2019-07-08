#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int v1;
    int v2;
    int weight;
    Edge()
    {
        this->v1 = 0;
        this->v2 = 0;
        this->weight = 0;
    }
};

pair<int, int> findParent(int v1, int v2, int parent[])
{
    while (parent[v1] != v1)
    {
        v1 = parent[v1];
    }
    while (parent[v2] != v2)
    {
        v2 = parent[v2];
    }
    pair<int, int> p;
    p.first = v1;
    p.second = v2;
    return p;
}

bool sortByWeight(Edge &A, Edge &B)
{
    return (A.weight < B.weight);
}

int main()
{
    int V, E;
    cin >> V >> E;

    Edge *inputEdge = new Edge[E];
    Edge *outputEdge = new Edge[V - 1];

    int parent[V];
    for (int i = 0; i < V; i++)
        parent[i] = i;

    for (int i = 0; i < E; i++)
    {
        int v1, v2, weight;
        cin >> v1 >> v2 >> weight;
        if (v1 > v2)
        {
            inputEdge[i].v1 = v2;
            inputEdge[i].v2 = v1;
            inputEdge[i].weight = weight;
        }
        else
        {
            inputEdge[i].v1 = v1;
            inputEdge[i].v2 = v2;
            inputEdge[i].weight = weight;
        }
    }

    sort(inputEdge, inputEdge + E, sortByWeight);

    int count = 0;
    for (int i = 0; i < E; i++)
    {
        if (count == V - 1)
            break;
        pair<int, int> p;
        p = findParent(inputEdge[i].v1, inputEdge[i].v2, parent);
        if (p.first != p.second)
        {
            parent[p.first] = p.second;
            outputEdge[count++] = inputEdge[i];
        }
    }

    for (int i = 0; i < V - 1; i++)
    {
        cout << outputEdge[i].v1 << " " << outputEdge[i].v2 << " " << outputEdge[i].weight << endl;
    }

    return 0;
}
