#include <bits/stdc++.h>
using namespace std;

int armyCount(int *arr, int n, int k, int visited[], int index)
{
    if (k == 0)
    {
        for (int i = 0; i < n; i++)
        {
            cout << visited[i] << " ";
        }
        cout << endl;

        return 1;
    }
    else if (k < 0)
        return 0;
    int val = 0;
    for (int i = index + 1; i < n; i++)
    {
        if (!visited[i])
        {
            visited[i] = 1;
            val += armyCount(arr, n, k - arr[i], visited, i);
            visited[i] = 0;
        }
    }
    return val;
}

int main()
{
    int n, k;
    cin >> n >> k;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int visited[n] = {0};
    cout << armyCount(arr, n, k, visited, 0);
    return 0;
}