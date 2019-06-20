#include <bits/stdc++.h>
using namespace std;

int getMaxMoney(int arr[], int n)
{
    int maxsum[n] = {0};
    maxsum[0] = arr[0];
    maxsum[1] = arr[1];
    for (int i = 2; i < n; i++)
    {
        int maxval = 0;
        for (int j = 0; j < i - 1; j++)
        {
            maxval = max(maxval, maxsum[j]);
        }
        maxsum[i] = maxval + arr[i];
    }
    return max(maxsum[n - 1], maxsum[n - 2]);
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << getMaxMoney(arr, n);
    return 0;
}