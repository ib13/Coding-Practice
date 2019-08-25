#include <bits/stdc++.h>
using namespace std;

int maxValue(int *wt, int *val, int n, int weight)
{
    int dp[n + 1][weight + 1];
    for (int i = 0; i < weight + 1; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 0; i < n + 1; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < weight + 1; j++)
        {
            if (j < wt[i - 1])
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], val[i - 1] + dp[i - 1][j - wt[i - 1]]);
            }
        }
    }
    return dp[n][weight];
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, weight;
        cin >> n >> weight;
        int *wt = new int[n];
        int *val = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> val[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> wt[i];
        }
        cout << maxValue(wt, val, n, weight) << endl;
    }
    return 0;
}