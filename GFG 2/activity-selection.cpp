#include <bits/stdc++.h>
using namespace std;

bool comparator(pair<int, int> p1, pair<int, int> p2)
{
    if (p1.second < p2.second)
        return true;
    return false;
}

int maxActivities(vector<pair<int, int>> arr)
{
    int n = arr.size();
    sort(arr.begin(), arr.end(), comparator);
    int noOfAct = 1;
    int maxAct = 1;
    int i = 0, j = 1;
    while (i < n && j < n)
    {
        if (arr[i].second > arr[j].first)
            j++;
        else
        {
            i = j;
            noOfAct++;
        }
    }
    return noOfAct;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr1[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr1[i];
        }
        int arr2[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr2[i];
        }
        vector<pair<int, int>> arr;
        for (int i = 0; i < n; i++)
        {
            pair<int, int> p;
            p.first = arr1[i];
            p.second = arr2[i];
            arr.push_back(p);
        }
        cout << maxActivities(arr) << endl;
    }
    return 0;
}