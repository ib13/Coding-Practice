#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int arr[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    int row = 0, col = 0;
    while (row < n && col < m)
    {
        if (row <= n / 2)
            for (int i = col; i < m - col; i++)
            {
                cout << arr[row][i] << " ";
            }
        if (col <= m / 2)
            for (int i = row + 1; i < n - row; i++)
            {
                cout << arr[i][m - col - 1] << " ";
            }
        if (row < n / 2)
            for (int i = m - col - 2; i >= col + 1; i--)
            {
                cout << arr[n - row - 1][i] << " ";
            }
        if (col < m / 2)
            for (int i = n - row - 2; i >= row + 1; i--)
            {
                cout << arr[i][col] << " ";
            }
        row++;
        col++;
    }

    return 0;
}