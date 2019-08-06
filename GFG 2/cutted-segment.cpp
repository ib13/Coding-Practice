#include <bits/stdc++.h>
using namespace std;

int maxCuts(int n, int x, int y, int z, int dp[])
{
    if (n == 0)
        return 0;
    int v1 = 0, v2 = 0, v3 = 0;
    if (n - x >= 0)
    {
        if (dp[n - x] != -1)
            v1 = dp[n - x];
        else
        {
            v1 = maxCuts(n - x, x, y, z, dp);
            dp[n - x] = v1;
        }
    }
    if (n - y >= 0)
    {
        if (dp[n - y] != -1)
            v2 = dp[n - y];
        else
        {
            v2 = maxCuts(n - y, x, y, z, dp);
            dp[n - y] = v2;
        }
    }
    if (n - z >= 0)
    {
        if (dp[n - z] != -1)
            v3 = dp[n - z];
        else
        {
            v3 = maxCuts(n - z, x, y, z, dp);
            dp[n - z] = v3;
        }
    }
    return 1 + max(max(v1, v2), v3);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x, y, z;
        cin >> n >> x >> y >> z;
        int dp[n + 1];
        for (int i = 0; i < n + 1; i++)
        {
            dp[i] = -1;
        }

        cout << maxCuts(n, x, y, z, dp) << endl;
    }
    return 0;
}