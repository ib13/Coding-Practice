#include <bits/stdc++.h>
using namespace std;

int editDist(string s1, string s2, int n, int m)
{
    int dp[n + 1][m + 1];
    dp[0][0] = 0;
    for (int i = 1; i < n + 1; i++)
    {
        dp[i][0] = dp[i - 1][0] + 1;
    }
    for (int i = 1; i < m + 1; i++)
    {
        dp[0][i] = dp[0][i - 1] + 1;
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min(min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i][j - 1]);
        }
    }
    return dp[n][m];
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        cout << editDist(s1, s2, n, m) << endl;
    }
    return 0;
}