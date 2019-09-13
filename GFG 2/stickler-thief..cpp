#include <bits/stdc++.h>
using namespace std;

int maxMoney(int *arr, int n)
{
    int dp[n];
    dp[0] = arr[0];
    dp[1] = max(arr[0], arr[1]);
    for (int i = 2; i < n; i++)
    {
        dp[i] = max(dp[i - 1], dp[i - 2] + arr[i]);
    }
    return max(dp[n - 1], dp[n - 2]);
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
        cout << maxMoney(arr, n) << endl;
    }
    return 0;
}