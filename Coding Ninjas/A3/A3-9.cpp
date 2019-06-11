#include <bits/stdc++.h>
using namespace std;

int minDistance(int arr[], int n)
{
    unordered_map<int, int> indexstore;
    int mindist = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (indexstore[arr[i]] > 0)
        {
            if (i + 1 - indexstore[arr[i]] < mindist)
            {
                mindist = i + 1 - indexstore[arr[i]];
            }
        }
        indexstore[arr[i]] = i + 1;
    }
    if (mindist == INT_MAX)
        return n;
    return mindist;
}

int main()
{
    int n = 0;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << minDistance(arr, n);
}
