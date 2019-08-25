#include <bits/stdc++.h>
using namespace std;

void sortByFreq(int *arr, int n)
{
    map<int, int> count;
    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }
    vector<pair<int, int>> v;
    for (auto it = count.begin(); it != count.end(); it++)
    {
        pair<int, int> p;
        p.first = it->second;
        p.second = it->first;
        v.push_back(p);
    }
    sort(v.begin(), v.end(), greater<pair<int, int>>());
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i].second;
    }

    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int *arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sortByFreq(arr, n);
    }
    return 0;
}