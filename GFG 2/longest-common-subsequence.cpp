#include <bits/stdc++.h>
using namespace std;

int findLCS(string s1, string s2)
{
    int l1 = s1.length();
    int l2 = s2.length();
    int dp[l1 + 1][l2 + 1];
    for (int i = 0; i < l1 + 1; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 0; i < l2 + 1; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 1; i < l1 + 1; i++)
    {
        for (int j = 1; j < l2 + 1; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[l1][l2];
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int l1, l2;
        cin >> l1 >> l2;
        string s1, s2;
        cin >> s1 >> s2;
        cout << findLCS(s1, s2) << endl;
    }
    return 0;
}