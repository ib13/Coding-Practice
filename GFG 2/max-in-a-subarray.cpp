#include <bits/stdc++.h>
using namespace std;

void findMaxSubArray(int *arr, int n, int k)
{
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
        findMaxSubArray(arr, n, k);
    }
    return 0;
}