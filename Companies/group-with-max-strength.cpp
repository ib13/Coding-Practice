#include <bits/stdc++.h>
using namespace std;

int TraverseStrength(vector<int> strength, int visited[], int n, int index, int adjMat[100][100])
{
    visited[index] = 1;
    int val = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && adjMat[i][index] == 1)
        {
            val += TraverseStrength(strength, visited, n, i, adjMat);
        }
    }
    return val + strength[index];
}

int findMaxStrength(vector<int> strength, vector<pair<int, int>> team, int n, int m)
{
    int adjMat[100][100] = {{0}};
    for (int i = 0; i < m; i++)
    {
        adjMat[team[i].first - 1][team[i].second - 1] = 1;
        adjMat[team[i].second - 1][team[i].first - 1] = 1;
    }

    int visited[n] = {0};
    int MaxStrength = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            int str = TraverseStrength(strength, visited, n, i, adjMat);
            if (str > MaxStrength)
            {
                MaxStrength = str;
            }
        }
    }
    return MaxStrength;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> strength;
    vector<pair<int, int>> team;

    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        strength.push_back(val);
    }
    for (int i = 0; i < m; i++)
    {
        pair<int, int> val;
        cin >> val.first;
        cin >> val.second;
        team.push_back(val);
    }
    cout << findMaxStrength(strength, team, n, m);
    return 0;
}