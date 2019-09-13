#include <bits/stdc++.h>
using namespace std;

int ascBinarySearch(int *arr, int l, int r, int x)
{
    if (r < l)
        return -1;
    int mid = (l + r) / 2;
    if (arr[mid] == x)
        return mid;
    else if (arr[mid] > x)
        ascBinarySearch(arr, l, mid - 1, x);
    else
        ascBinarySearch(arr, mid + 1, r, x);
}

int decBinarySearch(int *arr, int l, int r, int x)
{
    if (r < l)
        return -1;
    int mid = (l + r) / 2;
    if (arr[mid] == x)
        return mid;
    else if (arr[mid] < x)
        decBinarySearch(arr, l, mid - 1, x);
    else
        decBinarySearch(arr, mid + 1, r, x);
}

int bitonicPoint(int *arr, int n, int l, int r)
{
    int mid = (l + r) / 2;
    if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
        return mid;
    else if (arr[mid] > arr[mid - 1] && arr[mid] < arr[mid + 1])
        bitonicPoint(arr, n, mid, r);
    else
        bitonicPoint(arr, n, l, mid);
}

int elementIndex(int *arr, int n, int x)
{
    int k = bitonicPoint(arr, n, 0, n - 1);
    if (x > arr[k])
        return -1;

    else if (x == arr[k])
        return k;
    else
    {
        int v1 = ascBinarySearch(arr, 0, k, x);
        if (v1 != -1)
            return v1;
        int v2 = decBinarySearch(arr, k + 1, n - 1, x);
        return v2;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n;
        int *arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cin >> x;
        cout << elementIndex(arr, n, x) << endl;
    }
    return 0;
}