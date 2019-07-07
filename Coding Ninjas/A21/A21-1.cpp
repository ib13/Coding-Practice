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
        if (!isParent(inputEdge[i].v1, inputEdge[i].v2, parent))
        {
        }
    }

    return 0;
}
