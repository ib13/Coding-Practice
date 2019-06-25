#include <iostream>
using namespace std;
#include <stdint.h>

int64_t bytelandianHelper(int64_t n, int64_t dp[])
{
    if (n == 1)
        return 1;
    if (n == 0)
        return 0;
    int64_t v1, v2, v3;
    if (dp[n / 2] >= 0)
        v1 = dp[n / 2];
    else
    {
        v1 = bytelandianHelper(n / 2, dp);
        dp[n / 2] = v1;
    }
    if (dp[n / 3] >= 0)
        v2 = dp[n / 3];
    else
    {
        v2 = bytelandianHelper(n / 3, dp);
        dp[n / 3] = v2;
    }
    if (dp[n / 4] >= 0)
        v3 = dp[n / 4];
    else
    {
        v3 = bytelandianHelper(n / 4, dp);
        dp[n / 4] = v3;
    }
    return max(v1 + v2 + v3, n);
}

int64_t bytelandian(int64_t n)
{
    int64_t dp[n + 1];
    for (int64_t i = 0; i <= n; i++)
    {
        dp[i] = -1;
    }
    return bytelandianHelper(n, dp);
}

int main()
{
    int64_t n;
    cin >> n;
    int64_t x = bytelandian(n);
    cout << x << endl;
}