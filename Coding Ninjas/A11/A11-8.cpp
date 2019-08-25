#include <bits/stdc++.h>
using namespace std;

int minHealthHelper(int grid[500][500], int r, int c, int i, int j, int dp[500][500], int &minval)
{
    if ((i == r - 1 && j == c - 1) || (i == r - 1 && j == c - 1))
        return 1;
    if (dp[i][j] != -1)
        return dp[i][j];
    int v1 = INT_MAX, v2 = INT_MAX;
    if (i + 1 < r)
    {
        v1 = minHealthHelper(grid, r, c, i + 1, j, dp, minval) - grid[i + 1][j];
    }
    if (j + 1 < c)
    {
        v2 = minHealthHelper(grid, r, c, i, j + 1, dp, minval) - grid[i][j + 1];
    }
    if (min(v1, v2) < 1)
    {
        dp[i][j] = 1;
        return 1;
    }
    dp[i][j] = min(v1, v2);
    return min(v1, v2);
}

int minHealth(int grid[500][500], int r, int c)
{
    int dp[500][500];
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            dp[i][j] = -1;
        }
    }
    int minval = INT_MIN;
    return minHealthHelper(grid, r, c, 0, 0, dp, minval);
    // return minval;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int r, c;
        cin >> r >> c;
        int grid[500][500];
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cin >> grid[i][j];
            }
        }
        cout << minHealth(grid, r, c) << endl;
    }

    return 0;
}