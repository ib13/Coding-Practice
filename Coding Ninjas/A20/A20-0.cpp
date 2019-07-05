#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int e;
    cin >> e;
    int adjacencyMatrix[n][n] = {0};
    for (int i = 0; i < e; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        adjacencyMatrix[v1][v2] = 1;
        adjacencyMatrix[v2][v1] = 1;
    }
    return 0;
}