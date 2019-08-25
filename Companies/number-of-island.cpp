#include <bits/stdc++.h>
using namespace std;

void searchGrid(int grid[100][100], int visited[100][100], int n, int m, int r, int c, set<pair<int, int>> &set1)
{
    visited[r][c] = 1;
    set1.insert(make_pair(r, c));
    if (!visited[r + 1][c] && grid[r + 1][c] == 1)
    {
        searchGrid(grid, visited, n, m, r + 1, c, set1);
    }
    if (!visited[r][c + 1] && grid[r][c + 1] == 1)
    {
        searchGrid(grid, visited, n, m, r, c + 1, set1);
    }
    if (!visited[r - 1][c] && grid[r - 1][c] == 1)
    {
        searchGrid(grid, visited, n, m, r - 1, c, set1);
    }
    if (!visited[r][c - 1] && grid[r][c - 1] == 1)
    {
        searchGrid(grid, visited, n, m, r, c - 1, set1);
    }
}

int noOfIslands(int grid[100][100], int n, int m)
{
    int visited[100][100] = {{0}};
    vector<set<pair<int, int>>> res;
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (!visited[i][j] && grid[i][j] == 1)
            {
                set<pair<int, int>> set1;
                searchGrid(grid, visited, n, m, i, j, set1);
                res.push_back(set1);
            }
        }
    }
    int count = 0;
    for (int i = 0; i < res.size(); i++)
    {
        int flag = 0;
        for (auto it = res[i].begin(); it != res[i].end(); it++)
        {
            int r1 = it->first;
            int c1 = it->second;
            if (grid[r1 - 1][c1 - 1] == 1 && res[i].find(make_pair(r1 - 1, c1 - 1)) == res[i].end())
            {
                flag = 1;
            }
            if (grid[r1][c1 - 1] == 1 && res[i].find(make_pair(r1, c1 - 1)) == res[i].end())
            {
                flag = 1;
            }
            if (grid[r1 + 1][c1 - 1] == 1 && res[i].find(make_pair(r1 + 1, c1 - 1)) == res[i].end())
            {
                flag = 1;
            }
            if (grid[r1 - 1][c1] == 1 && res[i].find(make_pair(r1 - 1, c1)) == res[i].end())
            {
                flag = 1;
            }
            if (grid[r1 + 1][c1] == 1 && res[i].find(make_pair(r1 + 1, c1)) == res[i].end())
            {
                flag = 1;
            }
            if (grid[r1 - 1][c1 + 1] == 1 && res[i].find(make_pair(r1 - 1, c1 + 1)) == res[i].end())
            {
                flag = 1;
            }
            if (grid[r1][c1 + 1] == 1 && res[i].find(make_pair(r1, c1 + 1)) == res[i].end())
            {
                flag = 1;
            }
            if (grid[r1 + 1][c1 + 1] == 1 && res[i].find(make_pair(r1 + 1, c1 + 1)) == res[i].end())
            {
                flag = 1;
            }
        }
        if (flag == 0)
            count++;
    }

    // for (int i = 0; i < res.size(); i++)
    // {
    //     cout << "Group " << i << endl;
    //     for (auto it = res[i].begin(); it != res[i].end(); it++)
    //     {
    //         cout << it->first << " " << it->second << endl;
    //     }
    // }
    return count;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int grid[100][100] = {{0}};
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            cin >> grid[i][j];
        }
    }
    cout << noOfIslands(grid, n, m);
    return 0;
}
/*
Test Case:
6 6
1 0 1 1 0 0
1 0 1 1 0 1
0 0 0 1 0 1
0 1 0 0 0 0
1 0 1 0 0 0
0 0 0 1 0 1

Output: 4
*/