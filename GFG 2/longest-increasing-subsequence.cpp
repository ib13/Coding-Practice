#include <bits/stdc++.h>
using namespace std;

int findLIS(int arr[], int n)
{
    int dp[n] = {0};
    dp[0] = 1;
    for (int i = 1; i < n; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i] && dp[i] < dp[j] + 1)
                dp[i] = dp[j] + 1;
        }
    }
    int maxVal = 0;
    for (int i = 0; i < n; i++)
    {
        maxVal = max(maxVal, dp[i]);
    }
    return maxVal;
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
        cout << findLIS(arr, n) << endl;
    }
    return 0;
}