#include <bits/stdc++.h>
using namespace std;
#define MAXN 51

int findCycle(char board[][MAXN], int x, int y, int xo, int yo, int n, int m, char ch, int visited[][MAXN], int k)
{
    visited[x][y] = 1;
    if ((x == (xo - 1) && y == (yo)) || (x == (xo + 1) && y == (yo)) || (x == (xo) && y == (yo - 1)) || (x == (xo) && y == (yo + 1)))
    {
        if (k <= 1)
            return 1;
    }
    for (int i = 0; i < 4; i++)
    {
        int cx, cy;
        if (i == 0)
        {
            cx = x + 1;
            cy = y;
        }
        else if (i == 1)
        {
            cx = x - 1;
            cy = y;
        }
        else if (i == 2)
        {
            cx = x;
            cy = y + 1;
        }
        else if (i == 3)
        {
            cx = x;
            cy = y - 1;
        }
        if (cx >= 0 && cy >= 0 && cx < n && cy < m)
        {
            if (board[cx][cy] == ch && visited[cx][cy] == 0)
            {
                int val = findCycle(board, cx, cy, xo, yo, n, m, ch, visited, k - 1);
                if (val == 1)
                    return 1;
            }
        }
    }
    visited[x][y] = 0;
    return 0;
}

int solve(char board[][MAXN], int n, int m)
{
    int visited[MAXN][MAXN] = {0};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int val = findCycle(board, i, j, i, j, n, m, board[i][j], visited, 4);
            if (val == 1)
                return 1;
        }
    }
    return 0;
}

int main()
{
    int N, M, i;
    char board[MAXN][MAXN];
    cin >> N >> M;
    for (i = 0; i < N; i++)
    {
        cin >> board[i];
    }
    cout << solve(board, N, M) << endl;
}