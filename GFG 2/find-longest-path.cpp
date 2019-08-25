#include <bits/stdc++.h>
using namespace std;

int findUpper(int arr[100][100], int i, int j, int visited[100][100], int n)
{
    visited[i][j] = 1;
    int v1 = 0, v2 = 0, v3 = 0, v4 = 0;

    if (i - 1 >= 0 && arr[i - 1][j] == arr[i][j] + 1 && !visited[i - 1][j])
    {
        v1 = findUpper(arr, i - 1, j, visited, n);
    }
    if (j - 1 >= 0 && arr[i][j - 1] == arr[i][j] + 1 && !visited[i][j - 1])
    {
        v2 = findUpper(arr, i, j - 1, visited, n);
    }
    if (i + 1 < n && arr[i + 1][j] == arr[i][j] + 1 && !visited[i + 1][j])
    {
        v3 = findUpper(arr, i + 1, j, visited, n);
    }
    if (j + 1 < n && arr[i][j + 1] == arr[i][j] + 1 && !visited[i][j + 1])
    {
        v4 = findUpper(arr, i, j + 1, visited, n);
    }
    return 1 + max(max(max(v1, v2), v3), v4);
}

int findLower(int arr[100][100], int i, int j, int visited[100][100], int n)
{
    visited[i][j] = 1;
    int v1 = 0, v2 = 0, v3 = 0, v4 = 0;

    if (i - 1 >= 0 && arr[i - 1][j] == arr[i][j] - 1 && !visited[i - 1][j])
    {
        v1 = findLower(arr, i - 1, j, visited, n);
    }
    if (j - 1 >= 0 && arr[i][j - 1] == arr[i][j] - 1 && !visited[i][j - 1])
    {
        v2 = findLower(arr, i, j - 1, visited, n);
    }
    if (i + 1 < n && arr[i + 1][j] == arr[i][j] - 1 && !visited[i + 1][j])
    {
        v3 = findLower(arr, i + 1, j, visited, n);
    }
    if (j + 1 < n && arr[i][j + 1] == arr[i][j] - 1 && !visited[i][j + 1])
    {
        v4 = findLower(arr, i, j + 1, visited, n);
    }
    return 1 + max(max(max(v1, v2), v3), v4);
}

int findLongestPath(int arr[100][100], int n)
{
    int PathLength = 1;
    int visited[100][100] = {{0}};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visited[i][j])
            {
                int lowerLen = findLower(arr, i, j, visited, n) - 1;
                // cout << "[ " << lowerLen << " ";
                int upperLen = findUpper(arr, i, j, visited, n);
                // cout << upperLen << " ]";
                PathLength = max(lowerLen + upperLen, PathLength);
            }
        }
    }
    return PathLength;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int arr[100][100];
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> arr[i][j];
            }
        }
        cout << findLongestPath(arr, n) << endl;
    }
    return 0;
}