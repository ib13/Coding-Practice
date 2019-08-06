#include <bits/stdc++.h>
using namespace std;

void profitDays(int arr[], int n)
{
    int i = 0;
    int j = 0;
    int count = 0;
    while (i < n && j < n - 1)
    {
        if (arr[j] < arr[j + 1])
        {
            j++;
        }
        else
        {
            if (i < j)
            {

                count++;
                cout << "(" << i << " " << j << ") ";
            }
            i = j + 1;
            j = i;
        }
    }
    if (j == n - 1 && i < j)
    {
        count++;
        cout << "(" << i << " " << j << ") ";
    }
    if (count == 0)
        cout << "No Profit";
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int *arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        profitDays(arr, n);
    }
    return 0;
}