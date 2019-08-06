#include <bits/stdc++.h>
using namespace std;

bool isSubsetSumHelper1(int *arr, int n, int s, int curr_sum, int visited[])
{
    if (s == curr_sum)
        return 1;

    if (curr_sum > s)
        return 0;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && curr_sum + arr[i] <= s)
        {
            visited[i] = 1;
            int val = isSubsetSumHelper1(arr, n, s, curr_sum + arr[i], visited);
            visited[i] = 0;
            if (val == 1)
                return 1;
        }
    }
    return 0;
}

bool isSubsetSumHelper2(int *arr, int n, int s, int curr_sum, int dp[], int visited[])
{
    if (s == curr_sum)
        return 1;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && curr_sum + arr[i] <= s)
        {
            visited[i] = 1;
            int val;
            if (dp[curr_sum + arr[i]] == -1)
            {
                val = isSubsetSumHelper2(arr, n, s, curr_sum + arr[i], dp, visited);
                dp[curr_sum + arr[i]] = val;
            }
            else
            {
                val = dp[curr_sum + arr[i]];
            }

            visited[i] = 0;
            if (val == 1)
                return 1;
        }
    }
    return 0;
}

bool isSubsetSum(int *arr, int n)
{
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        s += arr[i];
    }
    if (s % 2 == 1)
        return 0;
    sort(arr, arr + n);
    int visited[n] = {0};
    int dp[s];
    for (int i = 0; i < s; i++)
    {
        dp[i] = -1;
    }

    // return isSubsetSumHelper1(arr, n, s / 2, 0, visited);
    return isSubsetSumHelper2(arr, n, s / 2, 0, dp, visited);
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
        if (isSubsetSum(arr, n))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}