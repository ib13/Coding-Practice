#include <bits/stdc++.h>
using namespace std;

int findElement(int arr[], int n)
{
    int leftmax[n];
    int rightmin[n];
    leftmax[0] = arr[0];
    rightmin[n - 1] = arr[n - 1];
    for (int i = 1; i < n; i++)
    {
        leftmax[i] = max(leftmax[i - 1], arr[i]);
    }
    for (int i = n - 2; i >= 0; i--)
    {
        rightmin[i] = min(rightmin[i + 1], arr[i]);
    }
    for (int i = 1; i < n - 1; i++)
    {
        if (arr[i] >= leftmax[i - 1] && arr[i] <= rightmin[i + 1])
            return arr[i];
    }
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
        int *arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << findElement(arr, n) << endl;
    }
    return 0;
}