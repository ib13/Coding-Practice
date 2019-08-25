#include <bits/stdc++.h>
using namespace std;

int isPairSumDivisible(int *arr, int n, int k)
{
    if (n % 2 == 1)
        return 0;
    int hashmap[100000];
    memset(hashmap, 0, sizeof(hashmap));
    for (int i = 0; i < n; i++)
    {
        hashmap[arr[i] % k]++;
    }
    for (int i = 0; i < n; i++)
    {
        if (hashmap[arr[i] % k] != hashmap[(k - (arr[i] % k)) % k])
            return 0;
    }
    return 1;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n;
        int *arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cin >> k;
        if (isPairSumDivisible(arr, n, k))
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}