#include <bits/stdc++.h>
using namespace std;

int minDifference(int arr[], int n, int m)
{
    int minval = INT_MAX;
    sort(arr, arr + n);
    for (int i = 0; i <= n - m; i++)
    {
        minval = min(minval, arr[i + m - 1] - arr[i]);
    }
    return minval;
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
        int m;
        cin >> m;
        cout << minDifference(arr, n, m) << endl;
    }
    return 0;
}