#include <bits/stdc++.h>
using namespace std;

int minDeletions(int *arr, int n, int k)
{
    sort(arr, arr + n);
    int minDel = INT_MAX;
    for (int i = 0; i < n - 1; i++)
    {
        int minelement = arr[i];
        int del = 0;
        for (int j = i; j < n; j++)
        {
            if (arr[j] - minelement > k)
            {
                del += arr[j] - minelement - k;
            }
        }
        for (int j = 0; j < i; j++)
        {
            del += arr[j];
        }
        minDel = min(minDel, del);
    }
    return minDel;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int *arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << minDeletions(arr, n, k) << endl;
    }
    return 0;
}