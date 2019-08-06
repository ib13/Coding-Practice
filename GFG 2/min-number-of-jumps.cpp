#include <bits/stdc++.h>
using namespace std;

int minJumps3(int *arr, int n)
{
    if (arr[0] == 0)
        return -1;
    int maxReach = arr[0];
    int steps = arr[0];
    int jumps = 1;
    for (int i = 1; i < n; i++)
    {
        if (i == n - 1)
            return jumps;
        maxReach = max(maxReach, i + arr[i]);
        steps--;
        if (steps == 0)
        {
            if (i >= maxReach)
                return -1;
            steps = maxReach - i;
            jumps++;
        }
    }
    return -1;
}

int minJumps2(int *arr, int n)
{
    int dp[n];
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        dp[i] = INT_MAX;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j <= i + arr[i]; j++)
        {
            if (dp[i] == INT_MAX)
                return -1;
            if (j < n)
            {
                dp[j] = min(dp[j], dp[i] + 1);
            }
        }
    }
    return dp[n - 1];
}

int minJumps1(int *arr, int n)
{
    int dp[n];
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        dp[i] = INT_MAX;
        for (int j = 0; j < i; j++)
        {
            if (i - j <= arr[j] && dp[i] > dp[j] + 1)
            {
                dp[i] = dp[j] + 1;
            }
        }
        if (dp[i] == INT_MAX)
            return -1;
    }
    return dp[n - 1];
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int *arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << minJumps3(arr, n) << endl;
    }
    return 0;
}