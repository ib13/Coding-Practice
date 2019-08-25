#include <bits/stdc++.h>
using namespace std;

int getSum(int grid[20][20], int n, int r, int c, int dp[20][20])
{
    if (r == n - 1)
        return grid[r][c];

    if (dp[r][c] != -1)
        return dp[r][c];

    int sum1 = 0, sum2 = 0, sum3 = 0;
    if (c - 1 >= 0)
    {
        if (dp[r + 1][c - 1] != -1)
            sum1 = dp[r + 1][c - 1];
        else
        {
            sum1 = getSum(grid, n, r + 1, c - 1, dp);
            dp[r + 1][c - 1] = sum1;
        }
    }
    if (dp[r + 1][c] != -1)
        sum2 = dp[r + 1][c];
    else
    {
        sum2 = getSum(grid, n, r + 1, c, dp);
        dp[r + 1][c] = sum2;
    }

    if (c + 1 < n)
    {
        if (dp[r + 1][c + 1] != -1)
            sum3 = dp[r + 1][c + 1];
        else
        {
            sum3 = getSum(grid, n, r + 1, c + 1, dp);
            dp[r + 1][c + 1] = sum3;
        }
    }
    return grid[r][c] + max(max(sum1, sum2), sum3);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int grid[20][20];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> grid[i][j];
            }
        }
        int dp[20][20];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                dp[i][j] = -1;
            }
        }

        int maxSum = 0;
        for (int i = 0; i < n; i++)
        {
            maxSum = max(maxSum, getSum(grid, n, 0, i, dp));
        }
        cout << maxSum << endl;
    }
    return 0;
}