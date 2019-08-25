#include <bits/stdc++.h>
using namespace std;

int dp[100][100];

int findSubsets(int n, int k, int index)
{
    if (k == 0)
        return 1;
    int val = 0;

    if (dp[k][index] == -1)
        for (int i = index; i < n; i++)
        {
            if (dp[k - 1][i] == -1)
            {
                int temp = findSubsets(n, k - 1, i);
                val += temp;
                dp[k - 1][i] = temp;
            }
            else
            {
                val += dp[k - 1][i];
            }
        }
    else
    {
        val += dp[k][index];
    }

    return val;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        // int *arr = new int[n];
        // for (int i = 0; i < n; i++)
        // {
        //     cin >> arr[i];
        // }
        for (int i = 0; i < 100; i++)
        {
            for (int j = 0; j < 100; j++)
            {
                dp[i][j] = -1;
            }
        }
        cout << findSubsets(n + 1, k - 1, 0) << endl;
    }
    return 0;
}