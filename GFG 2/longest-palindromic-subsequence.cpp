#include <bits/stdc++.h>
using namespace std;

int LongestPalSubSeq(string str)
{
    int len = str.length();
    int dp[len][len];
    for (int i = 0; i < len; i++)
    {
        for (int j = len - 1; j >= 0; j--)
        {
            if (j <= i)
            {
                if (i == j)
                {
                    dp[j][i] = 1;
                }
                else if (i == j + 1)
                {
                    if (str[i] == str[j])
                        dp[j][i] = 2;
                    else
                        dp[j][i] = 1;
                }
                else
                {
                    if (str[i] == str[j])
                    {
                        dp[j][i] = 2 + dp[j + 1][i - 1];
                    }
                    else
                    {
                        dp[j][i] = max(dp[j + 1][i], dp[j][i - 1]);
                    }
                }
            }
            else
            {
                dp[j][i] = 0;
            }
        }
    }
    // for (int i = 0; i < len; i++)
    // {
    //     for (int j = 0; j < len; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return dp[0][len - 1];
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        cout << LongestPalSubSeq(str) << endl;
    }
    return 0;
}