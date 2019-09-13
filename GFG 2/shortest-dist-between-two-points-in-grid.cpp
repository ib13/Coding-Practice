#include <bits/stdc++.h>
using namespace std;

int findPath(int grid[100][100], int sr, int sc, int er, int ec, int visited[100][100], int n, int m)
{
    if (sr == er && sc == ec)
        return 0;
    visited[sr][sc] = 1;
    int minPath = INT_MAX;
    if (sr - 1 >= 0 && !visited[sr - 1][sc] && grid[sr - 1][sc] == 1)
    {
        minPath = min(minPath, findPath(grid, sr - 1, sc, er, ec, visited, n, m));
    }
    if (sr + 1 < n && !visited[sr + 1][sc] && grid[sr + 1][sc] == 1)
    {
        minPath = min(minPath, findPath(grid, sr + 1, sc, er, ec, visited, n, m));
    }
    if (sc - 1 >= 0 && !visited[sr][sc - 1] && grid[sr][sc - 1] == 1)
    {
        minPath = min(minPath, findPath(grid, sr, sc - 1, er, ec, visited, n, m));
    }
    if (sc + 1 < m && !visited[sr][sc + 1] && grid[sr][sc + 1] == 1)
    {
        minPath = min(minPath, findPath(grid, sr, sc + 1, er, ec, visited, n, m));
    }
    visited[sr][sc] = 0;
    if (minPath == INT_MAX)
        return INT_MAX;
    return minPath + 1;
}

int minDist(int grid[100][100], int n, int m)
{
    pair<int, int> start;
    pair<int, int> end;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 5)
            {
                grid[i][j] = 1;
                start.first = i;
                start.second = j;
            }
            if (grid[i][j] == 6)
            {
                grid[i][j] = 1;
                end.first = i;
                end.second = j;
            }
        }
    }
    int visited[100][100] = {{0}};
    int val = findPath(grid, start.first, start.second, end.first, end.second, visited, n, m);
    if (val == INT_MAX)
        return -1;
    return val;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int grid[100][100];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        cout << minDist(grid, n, m) << endl;
    }
    return 0;
}