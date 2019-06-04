#include <iostream>
#include <algorithm>
using namespace std;

int MissingNumber(int arr[], int size)
{
    // O(n)
    int sum1 = 0, sum2 = 0;
    sum2 = (size - 1) * (size - 2) / 2;
    for (int i = 0; i < size; i++)
    {
        sum1 += arr[i];
    }
    // cout << sum1 << " " << sum2;

    return sum1 - sum2;

    // O(nlogn)
    // sort(arr, arr + size);
    // for (int i = 0; i < size - 1; i++)
    // {
    //     if (arr[i] == arr[i + 1])
    //         return arr[i];
    // }
}

int main()
{
    int size;
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout << MissingNumber(arr, size);
    return 0;
}