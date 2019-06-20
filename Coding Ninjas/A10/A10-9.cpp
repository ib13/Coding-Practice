#include <iostream>
#include <stdio.h>
using namespace std;

int getMin(int *arr, int n)
{
    int dp[n];
    dp[0] = 1;
    // First go from left to right and check for right value
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[i - 1])
            dp[i] = dp[i - 1] + 1;
        else
            dp[i] = 1;
    }
    // Since last element is only dependent on right value so we dont change that value

    // Now go from right to left and check with left value
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] > arr[i + 1] && dp[i] <= dp[i + 1])
            dp[i] = dp[i + 1] + 1;
    }
    int totalsum = 0;
    for (int i = 0; i < n; i++)
    {
        totalsum += dp[i];
    }
    return totalsum;
}

int main()
{

    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << getMin(arr, n);
    delete[] arr;
}
