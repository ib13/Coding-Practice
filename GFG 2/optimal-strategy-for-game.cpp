#include <bits/stdc++.h>
using namespace std;

int optimalStrategy(int *arr, int n)
{
    pair<int, int> dp[n][n];
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = make_pair(arr[i], 0);
    }

    for (int row = n - 1; row >= 0; row--)
    {
        for (int col = 0; col < n; col++)
        {
            if (row < col)
            {
                int v1 = arr[row] + dp[row + 1][col].second;
                int v2 = arr[col] + dp[row][col - 1].second;
                dp[row][col].first = max(v1, v2);
                dp[row][col].second = min(dp[row + 1][col].first, dp[row][col - 1].first);
            }
        }
    }
    return dp[0][n - 1].first;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int *arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << optimalStrategy(arr, n) << endl;
    }
    return 0;
}