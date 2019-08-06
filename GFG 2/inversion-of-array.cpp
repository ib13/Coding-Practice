#include <bits/stdc++.h>
using namespace std;

int merge(long long int arr[], long long int temp[], int left, int mid, int right)
{
    int i = left;
    int j = mid;
    int k = left;
    int inversionCount = 0;
    while (i < mid && j <= right)
    {
        if (arr[i] < arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            inversionCount += (mid - i);
        }
    }
    while (i < mid)
    {
        temp[k++] = arr[i++];
    }
    while (j <= right)
    {
        temp[k++] = arr[j++];
    }
    for (i = left; i <= right; i++)
    {
        arr[i] = temp[i];
    }
    return inversionCount;
}

int mergeSort(long long int arr[], long long int temp[], int left, int right)
{
    int inversionCount = 0;
    int mid = (left + right) / 2;
    if (left < right)
    {
        inversionCount = mergeSort(arr, temp, left, mid);
        inversionCount += mergeSort(arr, temp, mid + 1, right);
        inversionCount += merge(arr, temp, left, mid + 1, right);
    }
    return inversionCount;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        long long int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        long long int temp[n];
        cout << mergeSort(arr, temp, 0, n - 1) << endl;
    }
    return 0;
}