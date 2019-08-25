#include <bits/stdc++.h>
using namespace std;

int minAttempts(int n, int k)
{
    int dp[n + 1][k + 1];
    int res;
    for (int i = 0; i < n + 1; i++)
    {
        dp[i][0] = 0;
        dp[i][1] = 1;
    }
    for (int i = 0; i < k + 1; i++)
    {
        dp[0][i] = 0;
        dp[1][i] = i;
    }
    for (int i = 2; i < n + 1; i++)
    {
        for (int j = 2; j < k + 1; j++)
        {
            dp[i][j] = INT_MAX;
            for (int x = 1; x <= j; x++)
            {
                res = 1 + max(dp[i - 1][x - 1], dp[i][j - x]);
                if (res < dp[i][j])
                    dp[i][j] = res;
            }
        }
    }
    return dp[n][k];
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        cout << minAttempts(n, k) << endl;
    }
    return 0;
}