#include <bits/stdc++.h>
using namespace std;

int findMinTime(int arr[100][100], int r, int c)
{
    queue<pair<int, int>> q;
    int time = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (arr[i][j] == 2)
                q.push(make_pair(i, j));
        }
    }
    q.push(make_pair(-1, -1));
    while (!q.empty())
    {
        if (q.front().first == -1 && q.front().second == -1)
        {
            q.pop();
            if (!q.empty())
            {
                time++;
                q.push(make_pair(-1, -1));
            }
        }
        else
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            if (row - 1 >= 0 && arr[row - 1][col] == 1)
            {
                arr[row - 1][col] = 2;
                q.push(make_pair(row - 1, col));
            }
            if (col - 1 >= 0 && arr[row][col - 1] == 1)
            {
                arr[row][col - 1] = 2;
                q.push(make_pair(row, col - 1));
            }
            if (row + 1 < r && arr[row + 1][col] == 1)
            {
                arr[row + 1][col] = 2;
                q.push(make_pair(row + 1, col));
            }
            if (col + 1 < c && arr[row][col + 1] == 1)
            {
                arr[row][col + 1] = 2;
                q.push(make_pair(row, col + 1));
            }
        }
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (arr[i][j] == 1)
                return -1;
        }
    }
    return time;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int r, c;
        cin >> r >> c;
        int arr[100][100];
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cin >> arr[i][j];
            }
        }
        cout << findMinTime(arr, r, c) << endl;
    }
    return 0;
}