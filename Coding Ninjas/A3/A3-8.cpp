// Incorrect
//Correct - https://www.geeksforgeeks.org/largest-subarray-with-equal-number-of-0s-and-1s/
#include <cmath>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int max(int arr[], int n)
{
    int sum = 0;
    int maxlen = 0;
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
            arr[i] = -1;
    }
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == 0)
        {
            maxlen = i + 1;
        }
        if (m[arr[sum]] > 0)
        {
            if (i - m[arr[sum]] + 1 > maxlen)
            {
                maxlen = i - m[arr[sum]] + 1;
            }
        }
        cout << maxlen << endl;
        m[arr[sum]] = i;
    }
    return maxlen;
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

    cout << max(arr, n);
}
