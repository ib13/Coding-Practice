#include <bits/stdc++.h>
using namespace std;

void findMinCoins2(int n, int coins[])
{
    int dp[10][n + 1];
    for (int i = 0; i < 10; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 1; i < n + 1; i++)
    {
        dp[0][i] = dp[0][i - 1] + 1;
    }
    for (int i = 1; i < 10; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (j < coins[i])
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - coins[i]]);
        }
    }
    int r = 9, c = n;
    while (r >= 0 && c > 0)
    {
        if (dp[r][c] == dp[r - 1][c])
        {
            r = r - 1;
        }
        else
        {
            cout << coins[r] << " ";
            c = c - coins[r];
        }
    }
    cout << endl;
}

int findMinCoins1(int n, int coins[], int dp[])
{
    if (n == 0)
        return 0;

    int minCoins = INT_MAX;
    int coinForMin = 1;
    for (int i = 0; i < 10; i++)
    {
        int val = INT_MAX;
        if (n - coins[i] >= 0)
        {
            if (dp[n - coins[i]] != -1)
            {
                val = dp[n - coins[i]];
            }
            else
            {
                val = findMinCoins1(n - coins[i], coins, dp);
                dp[n - coins[i]] = val;
            }
        }
        if (val < minCoins)
        {
            minCoins = val;
            coinForMin = coins[i];
        }
    }
    return 1 + minCoins;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int dp[n + 1];
        for (int i = 0; i < n + 1; i++)
        {
            dp[i] = -1;
        }
        int coins[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
        // cout << findMinCoins1(n, coins, dp) << endl;
        findMinCoins2(n, coins);
    }

    return 0;
}