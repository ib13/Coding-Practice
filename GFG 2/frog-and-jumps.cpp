#include <bits/stdc++.h>
using namespace std;

int countHops(int n, int dp[])
{
    if (n == 0)
        return 1;
    if (n == 1 && n == 2)
        return n;
    if (n == 3)
        return 4;
    int count1 = 0, count2 = 0, count3 = 0;
    if (n - 1 >= 0)
        if (dp[n - 1] != -1)
        {
            count1 = dp[n - 1];
        }
        else
        {
            count1 = countHops(n - 1, dp);
            dp[n - 1] = count1;
        }
    if (n - 2 >= 0)
        if (dp[n - 2] != -1)
        {
            count2 = dp[n - 2];
        }
        else
        {
            count2 = countHops(n - 2, dp);
            dp[n - 2] = count2;
        }
    if (n - 3 >= 0)
        if (dp[n - 3] != -1)
        {
            count3 = dp[n - 3];
        }
        else
        {
            count3 = countHops(n - 3, dp);
            dp[n - 3] = count3;
        }

    return count1 + count2 + count3;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int dp[n + 1];
        for (int i = 0; i < n + 1; i++)
        {
            dp[i] = -1;
        }

        cout << countHops(n, dp) << endl;
    }
    return 0;
}