#include <bits/stdc++.h>
using namespace std;

int findMinCount(int x, int n, int dp[])
{
    if (x == n)
        return 0;
    else if (x > n)
        return -1;
    int v1 = -1, v2 = -1;
    if (x + 1 <= n)
    {
        if (dp[x + 1] != -2)
            v1 = dp[x + 1];
        else
        {

            v1 = findMinCount(x + 1, n, dp);
            dp[x + 1] = v1;
        }
    }
    if (x * 2 <= n)
    {
        if (dp[x * 2] != -2)
            v2 = dp[x * 2];
        else
        {

            v2 = findMinCount(x * 2, n, dp);
            dp[x * 2] = v2;
        }
    }

    if (v1 == -1 && v2 == -1)
        return -1;
    else if (v1 == -1)
        return 1 + v2;
    else if (v2 == -1)
        return 1 + v1;
    else
        return 1 + min(v1, v2);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int dp[n + 1] = {0};
        for (int i = 0; i < n + 1; i++)
        {
            dp[i] = -2;
        }

        cout << 1 + findMinCount(1, n, dp) << endl;
    }
    return 0;
}