#include <bits/stdc++.h>
using namespace std;

void findPair(int *arr1, int *arr2, int n, int m, int x)
{
    sort(arr1, arr1 + n);
    // sort(arr2, arr2 + m);
    vector<pair<int, int>> res;
    int i = 0;
    map<int, int> mp;
    for (int i = 0; i < m; i++)
    {
        mp[arr2[i]] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        if (mp[x - arr1[i]])
        {
            res.push_back(make_pair(arr1[i], x - arr1[i]));
        }
    }

    int size = res.size() - 1;
    for (int i = 0; i < size; i++)
    {
        cout << res[i].first << " " << res[i].second << ", ";
    }
    if (res.size() == 0)
        cout << -1;
    else
        cout << res[res.size() - 1].first << " " << res[res.size() - 1].second;
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, x;
        cin >> n >> m >> x;
        int *arr1 = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr1[i];
        }
        int *arr2 = new int[m];
        for (int i = 0; i < m; i++)
        {
            cin >> arr2[i];
        }
        findPair(arr1, arr2, n, m, x);
    }
    return 0;
}