#include <bits/stdc++.h>
using namespace std;
#define ll long long int
pair<int, int> missingAndRepeatedNum(int *arr, int n)
{
    int store[n + 1] = {0};
    for (int i = 0; i < n; i++)
    {
        store[arr[i]]++;
    }
    pair<int, int> p;
    for (int i = 1; i <= n; i++)
    {
        if (store[i] == 2)
            p.first = i;
        if (store[i] == 0)
            p.second = i;
    }
    return p;
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
        pair<int, int> p = missingAndRepeatedNum(arr, n);
        cout << p.first << " " << p.second << endl;
    }
    return 0;
}