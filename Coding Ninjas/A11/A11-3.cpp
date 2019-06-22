#include <iostream>
using namespace std;

int findMaxSquareWithAllZerosHelper(int **arr, int row, int col, int **dp)
{
    for (int i = 0; i < row; i++)
        dp[i][0] = 1 - arr[i][0];
    for (int j = 0; j < col; j++)
        dp[0][j] = 1 - arr[0][j];

    for (int i = 1; i < row; i++)
    {
        for (int j = 1; j < col; j++)
        {
            if (arr[i][j] == 0)
                dp[i][j] = 1 + min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]);
            else
                dp[i][j] = 0;
        }
    }
    int maxval = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            maxval = max(maxval, dp[i][j]);
        }
    }

    return maxval;
}

int findMaxSquareWithAllZeros(int **arr, int row, int col)
{
    int **dp = new int *[row];
    for (int i = 0; i < row; i++)
    {
        dp[i] = new int[col];
    }
    return findMaxSquareWithAllZerosHelper(arr, row, col, dp);
}

int main()
{
    int **arr, n, m, i, j;
    cin >> n >> m;
    arr = new int *[n];
    for (i = 0; i < n; i++)
    {
        arr[i] = new int[m];
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << findMaxSquareWithAllZeros(arr, n, m) << endl;
    delete arr;
    return 0;
}