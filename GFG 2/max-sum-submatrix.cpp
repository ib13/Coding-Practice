#include <bits/stdc++.h>
using namespace std;

int maxSumMat(int grid[100][100], int n, int m)
{
    int dp[n];
    int currSum = 0;
    int maxSum = INT_MIN;
    int left = 0, right = 0, up = 0, down = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dp[j] = 0;
        }

        for (int j = i; j < m; j++)
        {
            for (int k = 0; k < n; k++)
            {
                dp[k] = dp[k] + grid[k][j];
                // cout << dp[k] << " ";
            }
            // cout << endl;
            int prevSum = 0;
            int tempUp = 0;
            for (int k = 0; k < n; k++)
            {
                if (prevSum < 0)
                {
                    tempUp = k;
                    currSum = dp[k];
                }
                else
                    currSum = dp[k] + prevSum;
                if (currSum > maxSum)
                {
                    maxSum = currSum;
                    left = i;
                    right = j;
                    up = tempUp;
                    down = k;
                }
                prevSum = currSum;
            }
            // cout << maxSum << " ";
        }
    }
    cout << left << " " << up << " " << right << " " << down << " ";
    return maxSum;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int grid[100][100];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        cout << maxSumMat(grid, n, m) << endl;
    }
    return 0;
}