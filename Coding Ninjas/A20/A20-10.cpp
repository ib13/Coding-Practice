#include <iostream>
#include <vector>
using namespace std;
#define NMAX 55

int findMaxCake(char cake[NMAX][NMAX], int x, int y, int n, int visited[NMAX][NMAX])
{
    visited[x][y] = 1;
    int maxval = 0;
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
        if (cx >= 0 && cy >= 0 && cx < n && cy < n)
        {
            if (cake[cx][cy] == '1' && visited[cx][cy] == 0)
            {
                int val = findMaxCake(cake, cx, cy, n, visited);
                maxval+=val;
            }
        }
    }
    return maxval + 1;
}

int solve(int n, char cake[NMAX][NMAX])
{
    int visited[NMAX][NMAX] = {0};
    int maxval = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (cake[i][j] == '1' && visited[i][j] == 0)
            {
                int val = findMaxCake(cake, i, j, n, visited);
                maxval = max(val, maxval);
            }
        }
    }
    return maxval;
}

char cake[NMAX][NMAX];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%s", cake[i]);
    }
    cout << solve(n, cake) << endl;
}