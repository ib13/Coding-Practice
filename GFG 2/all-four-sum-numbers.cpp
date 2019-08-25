#include <bits/stdc++.h>
using namespace std;

void allFourSum(int *arr, int n, int sumval)
{
    sort(arr, arr + n);
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                for (int l = k + 1; l < n; l++)
                {
                    if (arr[i] + arr[j] + arr[k] + arr[l] == sumval)
                        cout << arr[i] << " " << arr[j] << " " << arr[k] << " " << arr[l] << " $";
                }
            }
        }
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
        allFourSum(arr, n, k);
    }
    return 0;
}