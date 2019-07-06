#include <bits/stdc++.h>
using namespace std;
#define MAXN 102

int solution(char Graph[][MAXN], int N, int M, int x, int y, string word, int visited[][MAXN])
{
    if (word.length() == 0)
        return 1;
    int val = 0;
    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            int xi = x + i;
            int yj = y + j;
            if (xi >= 0 && yj >= 0 && xi < N && yj < M)
            {
                if (Graph[xi][yj] == word[0] && visited[xi][yj] == 0)
                {
                    visited[xi][yj] = 1;
                    val = solution(Graph, N, M, xi, yj, word.substr(1), visited);
                    visited[xi][yj] = 0;
                    if (val == 1)
                        return 1;
                }
            }
        }
    }
    return 0;
}

int solve(char Graph[][MAXN], int N, int M)
{
    int visited[MAXN][MAXN] = {0};
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (Graph[i][j] == 'C' && visited[i][j] == 0)
            {
                visited[i][j] = 1;
                int val = solution(Graph, N, M, i, j, "ODINGNINJA", visited);
                visited[i][j] = 0;
                if (val == 1)
                    return 1;
            }
        }
    }
    return 0;
}

int main()
{
    int N, M, i;
    char Graph[MAXN][MAXN];
    cin >> N >> M;
    for (i = 0; i < N; i++)
    {
        cin >> Graph[i];
    }
    cout << solve(Graph, N, M) << endl;
}