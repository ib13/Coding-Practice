#include <bits/stdc++.h>
using namespace std;

int zigZagSumHelper(int arr[100][100], int n, int row, int col, int dp[100][100])
{
    if (row == n - 1)
        return arr[row][col];

    int arrSum = 0;
    for (int i = 0; i < n; i++)
    {
        if (i != col)
        {
            int val;
            if (dp[row + 1][i] != -1)
            {
                val = dp[row + 1][i];
            }
            else
            {
                val = zigZagSumHelper(arr, n, row + 1, i, dp);
                dp[row + 1][i] = val;
            }
            arrSum = max(arrSum, val);
        }
    }
    return arrSum + arr[row][col];
}

int zigZagSum(int arr[100][100], int n)
{
    int dp[100][100];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dp[i][j] = -1;
        }
    }
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res = max(res, zigZagSumHelper(arr, n, 0, i, dp));
    }

    return res;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[100][100];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> arr[i][j];
            }
        }
        cout << zigZagSum(arr, n) << endl;
    }
    return 0;
}