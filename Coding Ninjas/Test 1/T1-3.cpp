#include <bits/stdc++.h>
using namespace std;

bool findPairs(int arr[], int n)
{
    unordered_map<int, bool> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (m[arr[i] + arr[j]] != 0)
            {
                return true;
            }
            else
            {
                m[arr[i] + arr[j]] = 1;
            }
        }
    }
    return false;
}

int main()
{
    int n = 0;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    if (findPairs(arr, n))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
}
