#include <bits/stdc++.h>
using namespace std;

int equilibriumPoint(int arr[], int n)
{
    if (n == 1)
        return 1;
    int leftSum[n];
    leftSum[0] = arr[0];
    int rightSum[n];
    rightSum[n - 1] = arr[n - 1];
    for (int i = 1; i < n; i++)
    {
        leftSum[i] = leftSum[i - 1] + arr[i];
    }
    for (int i = n - 2; i >= 0; i--)
    {
        rightSum[i] = rightSum[i + 1] + arr[i];
    }
    for (int i = 1; i < n - 1; i++)
    {
        if (leftSum[i - 1] == rightSum[i + 1])
        {
            return i + 1;
        }
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
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << equilibriumPoint(arr, n) << endl;
    }
    return 0;
}
