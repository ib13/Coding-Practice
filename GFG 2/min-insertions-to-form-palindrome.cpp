#include <bits/stdc++.h>
using namespace std;

int minInsertions(string s)
{
    int n = s.length();
    int dp[n][n] = {{0}};
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if (j < i)
            {
                if (s[i] == s[j])
                {
                    dp[j][i] = dp[j + 1][i - 1];
                }
                else
                {
                    dp[j][i] = min(dp[j + 1][i], dp[j][i - 1]) + 1;
                }
            }
        }
    }
    return dp[0][n - 1];
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        cout << minInsertions(s) << endl;
    }
    return 0;
}