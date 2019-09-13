#include <bits/stdc++.h>
using namespace std;

int minCuts(int n, int x, int y, int z, int dp[])
{
    if (n == 0)
        return 0;
    if (dp[n] != -1)
    {
        return dp[n];
    }
    int v1 = INT_MIN, v2 = INT_MIN, v3 = INT_MIN;
    if (n - x >= 0)
    {
        if (dp[n - x] != -1)
        {
            v1 = dp[n - x];
        }
        else
        {
            v1 = 1 + minCuts(n - x, x, y, z, dp);
            dp[n - x] = v1;
        }
    }
    if (n - y >= 0)
    {
        if (dp[n - y] != -1)
        {
            v2 = dp[n - y];
        }
        else
        {
            v2 = 1 + minCuts(n - y, x, y, z, dp);
            dp[n - y] = v2;
        }
    }
    if (n - z >= 0)
    {
        if (dp[n - z] != -1)
        {
            v3 = dp[n - z];
        }
        else
        {
            v3 = 1 + minCuts(n - z, x, y, z, dp);
            dp[n - z] = v3;
        }
    }
    dp[n] = max(max(v1, v2), v3);
    return dp[n];
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int x, y, z;
        cin >> x >> y >> z;
        int dp[n + 1];
        for (int i = 0; i < n + 1; i++)
        {
            dp[i] = -1;
        }

        cout << minCuts(n, x, y, z, dp) << endl;
    }
    return 0;
}