#include <bits/stdc++.h>
using namespace std;

void printMatrix(int arr[100][100], int k, int l, int i, int j)
{
    for (int row = k; row <= i; row++)
    {
        for (int col = l; col <= j; col++)
        {
            cout << arr[row][col] << " ";
        }
        cout << endl;
    }
}

bool isSorted(int arr[100][100], int k, int l, int i, int j)
{
    for (int row = k; row <= i; row++)
    {
        for (int col = l; col <= j; col++)
        {
            if (row - 1 >= k && col - 1 >= l)
            {
                if (arr[row][col] <= arr[row - 1][col] || arr[row][col] <= arr[row][col - 1])
                    return false;
            }
            if (row - 1 >= k)
            {
                if (arr[row][col] <= arr[row - 1][col])
                    return false;
            }
            if (col - 1 >= l)
            {
                if (arr[row][col] <= arr[row][col - 1])
                    return false;
            }
        }
    }
    return true;
}

void allSubMatrix(int arr[100][100], int n, int m)
{
    int sri = 0, sci = 0, eri = 0, eci = 0;
    int maxSize = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k <= i; k++)
            {
                for (int l = 0; l <= j; l++)
                {

                    if (isSorted(arr, k, l, i, j))
                    {
                        // printMatrix(arr, k, l, i, j);
                        if ((i - k + 1) * (j - l + 1) > maxSize)
                        {
                            maxSize = (i - k + 1) * (j - l + 1);
                            sri = k;
                            sci = l;
                            eri = i;
                            eci = j;
                            // cout << "check" << maxSize << endl;
                        }
                    }
                }
            }
        }
    }
    printMatrix(arr, sri, sci, eri, eci);
}

// void largestSubMatrix(int arr[100][100], int n, int m)
// {
//     pair<int, int> dp[n][m];
//     dp[0][0] = make_pair(1, 1);
//     for (int i = 1; i < m; i++)
//     {
//         if (arr[0][i] > arr[0][i - 1])
//         {
//             dp[0][i].first = dp[0][i - 1].first + 1;
//             dp[0][i].second = 1;
//         }
//         else
//         {
//             dp[0][i].first = 1;
//             dp[0][i].second = 1;
//         }
//         cout << dp[0][i].first << " " << dp[0][i].second << " ";
//     }
//     for (int i = 1; i < n; i++)
//     {
//         if (arr[i][0] > arr[i - 1][0])
//         {
//             dp[i][0].second = dp[i - 1][0].second + 1;
//             dp[i][0].first = 1;
//         }
//         else
//         {
//             dp[i][0].second = 1;
//             dp[i][0].first = 1;
//         }
//         cout << dp[i][0].first << " " << dp[i][0].second << " ";
//     }
//     for (int i = 1; i < n; i++)
//     {
//         for (int j = 1; j < m; j++)
//         {
//             int length = dp[i - 1][j - 1].first;
//             int height = dp[i - 1][j - 1].second;
//         }
//     }
// }

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int arr[100][100];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> arr[i][j];
            }
        }
        allSubMatrix(arr, n, m);
    }
    return 0;
}