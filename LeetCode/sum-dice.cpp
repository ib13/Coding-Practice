#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long int

int numRollsToTarget(int d, int f, int target, int dp[31][1001])
{
    if (d == 0 && target == 0)
        return 1;
    if (d == 0 && target != 0)
        return 0;
    if (target < 0)
        return 0;
    ll possibleValues = 0;
    for (int i = 1; i <= f; i++)
    {

        if (target - i >= 0)
        {
            ll val;
            if (dp[d - 1][target - i] == -1)
            {
                val = numRollsToTarget(d - 1, f, target - i, dp);
                dp[d - 1][target - i] = val;
            }
            else
            {
                val = dp[d - 1][target - i];
            }

            possibleValues = (possibleValues % mod + val % mod) % mod;
        }
    }
    return (int)possibleValues % mod;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int d, f, t;
        cin >> d >> f >> t;
        int dp[31][1001];
        for (int i = 0; i < 31; i++)
        {
            for (int j = 0; j < 1001; j++)
            {
                dp[i][j] = -1;
            }
        }

        cout << numRollsToTarget(d, f, t, dp) << endl;
        return 0;
    }
}