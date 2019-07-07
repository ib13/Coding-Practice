#include <iostream>
#include <vector>
using namespace std;

// int find3Cycle(int **adjacencyMatrix, int n, int index, int curr, int visited[], int len)
// {
//     visited[curr] = 1;
//     if (len == 1 && adjacencyMatrix[index][curr] == 1)
//         return 1;
//     if (len < 1)
//         return 0;
//     int cycles = 0;
//     for (int i = 1; i <= n; i++)
//     {
//         if (adjacencyMatrix[i][curr] == 1 && visited[i] == 0)
//         {
//             cycles += find3Cycle(adjacencyMatrix, n, index, i, visited, len - 1);
//         }
//     }
//     visited[curr] = 0;
//     return cycles;
// }

int solve(int n, int m, vector<int> u, vector<int> v)
{
    int **adjacencyMatrix = new int *[n + 1];
    for (int i = 0; i <= n; i++)
    {
        adjacencyMatrix[i] = new int[n + 1];
        for (int j = 0; j <= n; j++)
        {
            adjacencyMatrix[i][j] = 0;
        }
    }
    for (int i = 0; i < m; i++)
    {
        int v1 = u[i];
        int v2 = v[i];
        adjacencyMatrix[v1][v2] = 1;
        adjacencyMatrix[v2][v1] = 1;
    }
    int visited[n + 1] = {0};
    int cycles = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (adjacencyMatrix[i][j] == 1)
            {
                for (int k = 1; k <= n; k++)
                {
                    if (adjacencyMatrix[j][k] == 1 && k != i)
                    {
                        if (adjacencyMatrix[k][i] == 1)
                            cycles++;
                    }
                }
            }
        }
    }
    return cycles / 6;
}

int main()
{
    int n, m;
    vector<int> u, v;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        u.push_back(x);
    }
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    cout << solve(n, m, u, v) << endl;
}