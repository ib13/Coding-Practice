#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int findSum(int arr[], int n)
{
    int sumarr[n] = {0};
    sumarr[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (sumarr[i - 1] + arr[i] > arr[i])
            sumarr[i] = sumarr[i - 1] + arr[i];
        else
            sumarr[i] = arr[i];
    }
    int maxele = 0;
    for (int i = 0; i < n; i++)
        maxele = max(maxele, sumarr[i]);
    return maxele;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << findSum(arr, n);

    return 0;
}
