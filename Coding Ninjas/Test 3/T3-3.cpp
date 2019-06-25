#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

long long solve(int n)
{
    // dp1 for A,B,C and dp2 for D
    long long dp1[n + 1], dp2[n + 1];
    dp1[0] = dp2[0] = dp2[1] = 0;
    dp1[1] = 1;

    for (long long i = 2; i <= n; i++)
    {
        dp1[i] = ((2 * dp1[i - 1]) % mod + dp2[i - 1]) % mod;
        dp2[i] = (3 * dp1[i - 1]) % mod;
    }
    return dp2[n];
}

int main()
{
    int n;
    cin >> n;
    cout << solve(n) << endl;
}