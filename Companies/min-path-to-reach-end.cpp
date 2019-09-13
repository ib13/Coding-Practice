#include <bits/stdc++.h>
using namespace std;

int minDist(bool **matrix, int n, int m)
{
    bool tracePath[n][m] = {0};
    int dp[n][m];
    dp[0][0] = 0;
    for (int i = 1; i < n; i++)
    {
        if (dp[i - 1][0] != INT_MAX && matrix[i][0] == 1)
            dp[i][0] = 1 + dp[i - 1][0];
        else
            dp[i][0] = INT_MAX;
    }
    for (int j = 1; j < m; j++)
    {
        if (dp[0][j - 1] != INT_MAX && matrix[0][j] == 1)
            dp[0][j] = 1 + dp[0][j - 1];
        else
            dp[0][j] = INT_MAX;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (matrix[i][j] == 1)
            {
                if (dp[i - 1][j] == INT_MAX && dp[i][j - 1] == INT_MAX && dp[i - 1][j - 1] == INT_MAX)
                    dp[i][j] = INT_MAX;
                else
                    dp[i][j] = 1 + min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]);
            }
            else
                dp[i][j] = INT_MAX;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (dp[i][j] == INT_MAX)
                cout << "-"
                     << " ";
            else
                cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    if (dp[n - 1][m - 1] == INT_MAX)
        return -1;
    else
        return dp[n - 1][m - 1];
}

int main()
{
    int n, m;
    cin >> n >> m;
    bool **matrix = new bool *[n];
    for (int i = 0; i < n; i++)
    {
        matrix[i] = new bool[m];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }

    cout << minDist(matrix, n, m);
    return 0;
}