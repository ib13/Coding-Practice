#include <bits/stdc++.h>
using namespace std;

bool findNum(int *arr, int n, int x)
{
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        m[arr[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
        if (m[x - arr[i]] > 0)
        {
            if (x - arr[i] == arr[i] && m[x - arr[i]] > 1)
                return 1;
            if (x - arr[i] != arr[i])
                return 1;
        }
    }
    return 0;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int *arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        if (findNum(arr, n, x))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}