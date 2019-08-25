#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
int main()
{
    int t;
    cin >> t;
    long long int dp[101][101];
    for (int i = 1; i < 101; i++)
    {
        for (int j = 1; j < 101; j++)
        {
            if (i == 1 || j == 1)
                dp[i][j] = 1;
            else
                dp[i][j] = (dp[i][j - 1] % mod + dp[i - 1][j] % mod) % mod;
        }
    }
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        cout << dp[n][m] << endl;
    }
    return 0;
}