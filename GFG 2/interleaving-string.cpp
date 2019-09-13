#include <bits/stdc++.h>
using namespace std;

bool isInterleave(string A, string B, string C)
{
    int s1 = A.size();
    int s2 = B.size();
    int s3 = C.size();
    bool dp[s1 + 1][s2 + 1];
    memset(dp, 0, sizeof(dp));
    if (s1 + s2 != s3)
        return 0;

    for (int i = 0; i < s1 + 1; i++)
    {
        for (int j = 0; j < s2 + 1; j++)
        {
            if (i == 0 && j == 0)
                dp[i][j] = 1;
            else if (i == 0 && B[j - 1] == C[j - 1])
                dp[i][j] = dp[i][j - 1];
            else if (j == 0 && A[i - 1] == C[i - 1])
                dp[i][j] = dp[i - 1][j];
            else if (A[i - 1] == C[i + j - 1] && B[j - 1] != C[i + j - 1])
                dp[i][j] = dp[i - 1][j];
            else if (A[i - 1] != C[i + j - 1] && B[j - 1] == C[i + j - 1])
                dp[i][j] = dp[i][j - 1];
            else if (A[i - 1] == C[i + j - 1] && B[j - 1] == C[i + j - 1])
                dp[i][j] = (dp[i - 1][j] || dp[i][j - 1]);
        }
    }
    return dp[s1][s2];
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string A, B, C;
        cin >> A >> B >> C;
        cout << isInterleave(A, B, C) << endl;
    }
    return 0;
}