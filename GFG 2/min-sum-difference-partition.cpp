#include <bits/stdc++.h>
using namespace std;

int findMinDifferenceHelper(int *arr, int n, int totalSum, int currSum, int index, int dp[2500][50])
{
    if (index == n)
    {
        return abs(currSum - (totalSum - currSum));
    }
    int v1, v2;
    if (dp[currSum][index + 1] != -1)
        v1 = dp[currSum][index + 1];
    else
    {
        v1 = findMinDifferenceHelper(arr, n, totalSum, currSum, index + 1, dp);
        dp[currSum][index + 1] = v1;
    }
    if (dp[currSum + arr[index]][index + 1] != -1)
        v2 = dp[currSum + arr[index]][index + 1];
    else
    {
        v2 = findMinDifferenceHelper(arr, n, totalSum, currSum + arr[index], index + 1, dp);
        dp[currSum + arr[index]][index + 1] = v2;
    }

    return min(v1, v2);
}

int findMinDifference(int *arr, int n)
{
    int totalSum = 0;
    for (int i = 0; i < n; i++)
    {
        totalSum += arr[i];
    }
    int dp[2500][50];
    for (int i = 0; i < 2500; i++)
    {
        for (int j = 0; j < 50; j++)
        {
            dp[i][j] = -1;
        }
    }

    return findMinDifferenceHelper(arr, n, totalSum, 0, 0, dp);
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
        cout << findMinDifference(arr, n) << endl;
    }
    return 0;
}