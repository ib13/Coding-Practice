#include <bits/stdc++.h>
using namespace std;

int findMaxToys(int *arr, int n, int k)
{
    sort(arr, arr + n);
    int toysCount = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < k)
        {
            k -= arr[i];
            toysCount++;
        }
    }
    return toysCount;
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
        cout << findMaxToys(arr, n, k) << endl;
    }
    return 0;
}