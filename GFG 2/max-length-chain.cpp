#include <bits/stdc++.h>
using namespace std;

int maxChainLength(vector<pair<int, int>> arr)
{
    sort(arr.begin(), arr.end());
    int dp[arr.size()] = {0};
    dp[0] = 1;
    for (int i = 1; i < arr.size(); i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[j].second < arr[i].first && dp[i] < dp[j] + 1)
                dp[i] = dp[j] + 1;
        }
    }
    int maxval = 0;
    for (int i = 0; i < arr.size(); i++)
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
        vector<pair<int, int>> arr;
        for (int i = 0; i < n; i++)
        {
            pair<int, int> p;
            cin >> p.first;
            cin >> p.second;
            arr.push_back(p);
        }
        cout << maxChainLength(arr) << endl;
    }
    return 0;
}