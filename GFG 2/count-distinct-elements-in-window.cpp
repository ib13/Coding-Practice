#include <bits/stdc++.h>
using namespace std;

void findDistinct(int *arr, int n, int k)
{
    int m[10] = {0};
    vector<int> res;
    for (int i = 0; i < k; i++)
    {
        m[arr[i]]++;
    }
    int count = 0;
    for (int i = 0; i < 10; i++)
    {
        if (m[i] > 0)
            count++;
    }
    res.push_back(count);
    for (int i = k; i < n; i++)
    {
        count = 0;
        m[arr[i - k]]--;
        m[arr[i]]++;
        for (int j = 0; j < 10; j++)
        {
            if (m[j] > 0)
                count++;
        }
        res.push_back(count);
    }
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
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
        findDistinct(arr, n, k);
    }
    return 0;
}