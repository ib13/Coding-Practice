#include <bits/stdc++.h>
using namespace std;

int minCoins(int *arr, int n, int v)
{
    sort(arr, arr + n);
    int dp[n + 1][v + 1];
    for (int i = 0; i < n + 1; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 1; i < v + 1; i++)
    {
        dp[0][i] = INT_MAX;
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < v + 1; j++)
        {
            if (j < arr[i - 1])
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                int t1 = dp[i - 1][j];
                int t2 = dp[i][j - arr[i - 1]];
                if (t2 != INT_MAX)
                {
                    t2 = t2 + 1;
                }
                dp[i][j] = min(t1, t2);
            }
        }
    }
    // for (int i = 0; i < n + 1; i++)
    // {
    //     for (int j = 0; j < v + 1; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    if (dp[n][v] == INT_MAX)
        return -1;
    return dp[n][v];
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, v;
        cin >> v >> n;
        int *arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << minCoins(arr, n, v) << endl;
    }
    return 0;
}