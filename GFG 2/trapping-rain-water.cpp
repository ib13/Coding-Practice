#include <bits/stdc++.h>
using namespace std;

int totalWaterTrapped(int arr[], int n)
{
    int trappedWater = 0;
    int leftmax[n];
    int rightmax[n];
    leftmax[0] = arr[0];
    rightmax[n - 1] = arr[n - 1];
    for (int i = 1; i < n; i++)
    {
        leftmax[i] = max(arr[i], leftmax[i - 1]);
    }
    for (int i = n - 2; i >= 0; i--)
    {
        rightmax[i] = max(arr[i], rightmax[i + 1]);
    }
    for (int i = 1; i < n - 1; i++)
    {
        if (arr[i] < min(leftmax[i - 1], rightmax[i + 1]))
        {
            trappedWater += (min(leftmax[i - 1], rightmax[i + 1]) - arr[i]);
        }
    }
    return trappedWater;
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
        cout << totalWaterTrapped(arr, n) << endl;
    }
    return 0;
}