#include <bits/stdc++.h>
using namespace std;

int getCircularTour(vector<pair<int, int>> arr)
{
    int start = 0, fuelLeft = 0, deficit = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        fuelLeft += arr[i].first - arr[i].second;
        if (fuelLeft < 0)
        {
            start = i + 1;
            deficit += fuelLeft;
            fuelLeft = 0;
        }
    }
    if (fuelLeft + deficit > 0)
        return start;
    else
        return -1;
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
        cout << getCircularTour(arr) << endl;
    }
    return 0;
}