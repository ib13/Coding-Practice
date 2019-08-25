#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int getMaxDifference(ll *arr, int n)
{
    int maxDiff = -1;
    ll LMin[n];
    LMin[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        LMin[i] = min(LMin[i - 1], arr[i]);
    }
    ll RMax[n];
    RMax[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        RMax[i] = max(RMax[i + 1], arr[i]);
    }
    int i = 0;
    int j = 0;
    while (i < n && j < n)
    {
        if (LMin[i] < RMax[j])
        {
            maxDiff = max(maxDiff, j - i);
            j++;
        }
        else
            i++;
    }
    return maxDiff;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        ll *arr = new ll[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << getMaxDifference(arr, n) << endl;
    }
    return 0;
}