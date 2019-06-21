#include <iostream>
#include <limits.h>
using namespace std;

int mcmHelper(int *p, int s, int e, int n, int dp[][101])
{
    if (s >= e)
        return 0;
    if (s == e - 1)
        return 0;
    int minop = INT_MAX;
    int minindex;
    for (int i = s + 1; i <= e - 1; i++)
    {
        int val1, val2;
        if (dp[s][i] >= 0)
            val1 = dp[s][i];
        else
        {
            val1 = mcmHelper(p, s, i, n, dp);
            dp[s][i] = val1;
        }
        if (dp[i][e] >= 0)
            val2 = dp[i][e];
        else
        {
            val2 = mcmHelper(p, i, e, n, dp);
            dp[i][e] = val2;
        }

        int val = p[s] * p[i] * p[e] + val1 + val2;
        if (val < minop)
            minop = val;
    }
    return minop;
}

int mcm(int *p, int n)
{
    int dp[101][101];
    for (int i = 0; i <= 100; i++)
        for (int j = 0; j <= 100; j++)
            dp[i][j] = -1;

    return mcmHelper(p, 0, n, n, dp);
}

int main()
{
    int n;
    cin >> n;
    int *p = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        cin >> p[i];
    }
    cout << mcm(p, n);
}
