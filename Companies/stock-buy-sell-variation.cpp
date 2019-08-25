#include <bits/stdc++.h>
using namespace std;

vector<int> maxProfit(int *arr, int n)
{
    int s1 = -1, e1 = -1;
    int i = 0, j = 0;
    int profit = 0;
    while (i < n && j < n - 1)
    {
        while (j < n - 1 && arr[j] < arr[j + 1])
        {
            j++;
        }
        if (i != j)
        {
            if (arr[j] - arr[i] > profit)
            {
                s1 = i + 1;
                e1 = j + 1;
                profit = arr[j] - arr[i];
            }
        }
        i = j + 1;
        j = i;
    }
    vector<int> result;
    result.push_back(s1);
    result.push_back(e1);
    int s2 = e1, e2 = s1;
    i = 0, j = 0;
    int prevProfit = profit;
    profit = 0;

    while (i < n && j < n - 1)
    {
        while (j < n - 1 && arr[j] > arr[j + 1])
        {
            j++;
        }
        if (i != j)
        {
            if (arr[i] - arr[j] > profit && arr[i] - arr[j] > prevProfit)
            {
                s2 = i + 1;
                e2 = j + 1;
                profit = arr[i] - arr[j];
            }
        }
        i = j + 1;
        j = i;
    }
    result.push_back(e2);
    result.push_back(s2);
    return result;
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> result = maxProfit(arr, n);
    for (int i = 0; i < 4; i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}