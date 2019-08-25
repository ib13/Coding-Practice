#include <bits/stdc++.h>
using namespace std;

int minCuts(int n, int x, int y, int z, int dp[])
{
    if (n == 0)
        return 0;
    int v1 = INT_MAX, v2 = INT_MAX, v3 = INT_MAX;
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