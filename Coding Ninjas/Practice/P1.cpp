#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int itr = 0;
    int newarr[n];
    int i, j;
    int mid = n / 2;
    if (n % 2 == 0)
    {
        i = mid - 1;
        j = mid;
    }
    else
    {
        newarr[mid] = arr[itr++];
        i = mid - 1;
        j = mid + 1;
    }
    while (itr < n)
    {
        newarr[i--] = arr[itr++];
        newarr[j++] = arr[itr++];
    }
    for (i = 0; i < n; i++)
    {
        cout << newarr[i] << " ";
    }

    return 0;
}