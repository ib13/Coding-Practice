#include <bits/stdc++.h>
using namespace std;

int findMinIndex(int arr[], int n, int x)
{
    if (n == 0)
        return -1;
    if (arr[0] == x)
        return 0;
    int val = findMinIndex(arr + 1, n - 1, x);
    if (val >= 0)
        return 1 + val;
    else
        return val;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int x;
    cin >> x;

    cout << findMinIndex(arr, n, x);
    return 0;
}