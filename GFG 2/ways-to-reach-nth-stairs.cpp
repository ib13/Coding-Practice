#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
// int waysToReach(int n, int dp[])
// {
//     if (n == 0)
//         return 1;
//     if (dp[n] != -1)
//         return dp[n];
//     long long int c1 = 0, c2 = 0;
//     if (n - 1 >= 0)
//     {
//         if (dp[n - 1] != -1)
//             c1 = dp[n - 1];
//         else
//         {
//             c1 = waysToReach(n - 1, dp) % mod;
//             dp[n - 1] = c1;
//         }
//     }
//     if (n - 2 >= 0)
//     {
//         if (dp[n - 2] != -1)
//             c2 = dp[n - 2];
//         else
//         {
//             c2 = waysToReach(n - 2, dp) % mod;
//             dp[n - 2] = c2;
//         }
//     }
//     return (c1 % mod + c2 % mod) % mod;
// }

int main()
{
    int dp[100000];
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i < 100000; i++)
    {
        dp[i] = (dp[i - 1] % mod + dp[i - 2] % mod) % mod;
    }
    // waysToReach(100000, dp);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << dp[n] << endl;
    }
}