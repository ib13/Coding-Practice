#include <bits/stdc++.h>
using namespace std;

void kthLargest(int *arr, int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    if (k > n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << -1 << " ";
        }
        cout << endl;
        return;
    }
    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
        if (pq.size() != k)
            cout << -1 << " ";
        else
            cout << pq.top() << " ";
    }
    for (int i = k; i < n; i++)
    {
        if (arr[i] > pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
        cout << pq.top() << " ";
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> k >> n;
        int *arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        kthLargest(arr, n, k);
    }
    return 0;
}