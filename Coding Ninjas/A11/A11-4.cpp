#include <iostream>
using namespace std;

int knapsack(int *weights, int *values, int n, int maxWeight)
{
    // In each iteration we take a new weight and consider only the previous taken weights to fill
    // We take 2*maxWeight+1 array as value of one row depends only on previous row
    // So we keep changing the values of rows
    int dp[2][maxWeight + 1];
    for (int i = 0; i <= maxWeight; i++)
    {
        // for weight 0
        dp[0][i] = 0;
    }
    dp[1][0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= maxWeight; j++)
        {
            if (j < weights[i])
                dp[1][j] = dp[0][j];
            else
            {
                dp[1][j] = max(dp[0][j], values[i] + dp[0][j - weights[i]]);
            }
        }
        for (int i = 0; i <= maxWeight; i++)
        {
            dp[0][i] = dp[1][i];
        }
    }
    return dp[0][maxWeight];
}

int main()
{

    int n;
    cin >> n;
    int *weights = new int[n];
    int *values = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> weights[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> values[i];
    }

    int maxWeight;
    cin >> maxWeight;

    cout << knapsack(weights, values, n, maxWeight);
}
