#include <bits/stdc++.h>
using namespace std;

bool wordBoggleHelper(char boggle[7][7], int n, int m, string s, int len, int j, int k, int visited[7][7])
{
    if (len == 0)
        return true;
    visited[j][k] = 1;
    bool ans = false;
    for (int r = j - 1; r <= j + 1; r++)
    {
        for (int c = k - 1; c <= k + 1; c++)
        {
            if (r >= 0 && r < n && c >= 0 && c < m && s[0] == boggle[r][c] && !visited[r][c])
            {
                ans = ans || wordBoggleHelper(boggle, n, m, s.substr(1), len - 1, r, c, visited);
            }
        }
    }
    visited[j][k] = 0;
    return ans;
}

void wordBoggle(string dict[10], int x, char boggle[7][7], int n, int m)
{
    set<string> set1;
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                int visited[7][7] = {{0}};
                int len = dict[i].length() - 1;
                if (dict[i][0] == boggle[j][k])
                {
                    if (wordBoggleHelper(boggle, n, m, dict[i].substr(1), len, j, k, visited))
                    {
                        set1.insert(dict[i]);
                    }
                }
            }
        }
    }
    if (set1.empty())
        cout << -1;
    for (auto it = set1.begin(); it != set1.end(); it++)
    {
        cout << *it << " ";
    }

    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x;
        cin >> x;
        string dict[10];
        for (int i = 0; i < x; i++)
        {
            cin >> dict[i];
        }
        int n, m;
        cin >> n >> m;
        char boggle[7][7];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> boggle[i][j];
            }
        }
        wordBoggle(dict, x, boggle, n, m);
    }
    return 0;
}