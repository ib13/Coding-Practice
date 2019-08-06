#include <bits/stdc++.h>
using namespace std;

bool comparator(pair<pair<int, int>, int> p1, pair<pair<int, int>, int> p2)
{
    return p1.first.first * p1.first.second > p2.first.first * p2.first.second;
}

int maxHeight1(vector<pair<pair<int, int>, int>> box)
{
    int n = box.size();
    for (int i = 0; i < n; i++)
    {
        pair<pair<int, int>, int> p;
        p.first.first = box[i].first.first;
        p.first.second = box[i].second;
        p.second = box[i].first.second;
        box.push_back(p);
        p.first.first = box[i].first.second;
        p.first.second = box[i].second;
        p.second = box[i].first.first;
        box.push_back(p);
    }
    n = box.size();
    sort(box.begin(), box.end(), comparator);
    for (int i = 0; i < n; i++)
    {
        if (box[i].first.first < box[i].first.second)
        {
            int temp = box[i].first.first;
            box[i].first.first = box[i].first.second;
            box[i].first.second = temp;
        }
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << "L: " << box[i].first.first << " ";
    //     cout << "R: " << box[i].first.second << " ";
    //     cout << "H: " << box[i].second << endl;
    // }

    int dp[n];
    for (int i = 0; i < n; i++)
    {
        dp[i] = box[i].second;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (box[j].first.first > box[i].first.first && box[j].first.second > box[i].first.second && dp[i] < dp[j] + box[i].second)
                dp[i] = dp[j] + box[i].second;
        }
    }
    int maxval = 0;
    for (int i = 0; i < n; i++)
    {
        maxval = max(maxval, dp[i]);
    }
    return maxval;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<pair<pair<int, int>, int>> box;
        for (int i = 0; i < n; i++)
        {
            pair<pair<int, int>, int> p;
            cin >> p.first.first;
            cin >> p.first.second;
            cin >> p.second;
            box.push_back(p);
        }
        cout << maxHeight1(box) << endl;
    }
    return 0;
}