#include <bits/stdc++.h>
using namespace std;

void reverseInGroups(int arr[], int n, int k)
{
    int i = 0;
    while (i + k < n)
    {
        reverse(arr + i, arr + i + k);
        i += k;
    }
    reverse(arr + i, arr + n);
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
        reverseInGroups(arr, n, k);
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    return 0;
}