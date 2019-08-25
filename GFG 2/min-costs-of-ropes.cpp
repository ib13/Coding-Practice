#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll minCost(ll *arr, int n)
{
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
    }
    ll minCost = 0;
    while (pq.size() != 1)
    {
        ll min1 = pq.top();
        pq.pop();
        ll min2 = pq.top();
        pq.pop();
        pq.push(min1 + min2);
        minCost += min1 + min2;
    }
    return minCost;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        ll *arr = new ll[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << minCost(arr, n) << endl;
    }
    return 0;
}