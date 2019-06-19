#include <bits/stdc++.h>
using namespace std;

void printPathHelper(int **input, int n, int x, int y, int **visited)
{
    if (x == n - 1 && y == n - 1)
    {
        visited[x][y] = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << visited[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        visited[x][y] = 0;
    }

    if (x < 0 || y < 0 || x >= n || y >= n || input[x][y] == 0 || visited[x][y] == 1)
        return;

    visited[x][y] = 1;
    printPathHelper(input, n, x + 1, y, visited);
    printPathHelper(input, n, x, y + 1, visited);
    printPathHelper(input, n, x, y - 1, visited);
    printPathHelper(input, n, x - 1, y, visited);
    visited[x][y] = 0;
}

bool hasPathHelper(int **input, int n, int x, int y, int **visited)
{
    if (x == n - 1 && y == n - 1)
        return true;

    if (x < 0 || y < 0 || x >= n || y >= n || input[x][y] == 0 || visited[x][y] == 1)
        return false;

    visited[x][y] = 1;
    if (hasPathHelper(input, n, x + 1, y, visited))
        return true;
    if (hasPathHelper(input, n, x, y + 1, visited))
        return true;
    if (hasPathHelper(input, n, x - 1, y, visited))
        return true;
    if (hasPathHelper(input, n, x, y - 1, visited))
        return true;
    visited[x][y] = 0;

    return false;
}

bool hasPath(int **input, int n)
{
    int **visited = new int *[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            visited[i][j] = 0;
        }
    }
    printPathHelper(input, n, 0, 0, visited);
    return hasPathHelper(input, n, 0, 0, visited);
}

int main()
{
    int n;
    cin >> n;
    int **input = new int *[n];
    for (int i = 0; i < n; i++)
    {
        input[i] = new int[n];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> input[i][j];
        }
    }
    if (hasPath(input, n))
    {
        cout << "Path exist";
    }
    else
    {
        cout << "Path does not exist.";
    }

    return 0;
}