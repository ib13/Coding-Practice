#include <bits/stdc++.h>
using namespace std;

int maxSumSubsequence(int *arr, int n)
{
    int dp[n] = {0};
    for (int i = 0; i < n; i++)
    {
        dp[i] = arr[i];
    }

    dp[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i] && dp[i] < dp[j] + arr[i])
            {
                dp[i] = dp[j] + arr[i];
            }
        }
    }
    int maxSum = 0;
    for (int i = 0; i < n; i++)
    {
        maxSum = max(maxSum, dp[i]);
    }
    return maxSum;
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
        cout << maxSumSubsequence(arr, n) << endl;
    }
    return 0;
}