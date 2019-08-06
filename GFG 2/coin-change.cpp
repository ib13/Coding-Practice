#include <bits/stdc++.h>
using namespace std;

int coinChange(int *arr, int n, int s)
{
    int dp[n + 1][s + 1];
    sort(arr, arr + n);
    for (int j = 0; j < s + 1; j++)
    {
        dp[0][j] = 0;
    }
    dp[0][0] = 1;
    for (int i = 1; i < n + 1; i++)
    {
        dp[i][0] = 1;
        for (int j = 1; j < s + 1; j++)
        {
            if (j < arr[i - 1])
                dp[i][j] = dp[i - 1][j];
            else
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - arr[i - 1]];
            }
        }
    }
    return dp[n][s];
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
        int s;
        cin >> s;
        cout << coinChange(arr, n, s) << endl;
    }
    return 0;
}