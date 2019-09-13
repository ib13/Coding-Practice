#include <bits/stdc++.h>
using namespace std;

int majorityElement(int *arr, int n)
{
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        m[arr[i]]++;
        if (m[arr[i]] > n / 2)
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
        cout << majorityElement(arr, n) << endl;
    }
    return 0;
}