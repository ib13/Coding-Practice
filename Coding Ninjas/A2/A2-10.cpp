#include <iostream>
#include <algorithm>
using namespace std;

int platformsNeeded(int arrival[], int departure[], int n)
{
    sort(arrival, arrival + n);
    sort(departure, departure + n);
    int i = 0, j = 0;
    int min_platforms = 0;
    int plt = 0;
    while (i < n && j < n)
    {
        if (arrival[i] < departure[j])
        {
            i++;
            plt++;
        }
        else
        {
            j++;
            plt--;
        }
        min_platforms = max(min_platforms, plt);
    }
    return min_platforms;
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    int *dep = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> dep[i];
    }
    cout << platformsNeeded(arr, dep, n);
}
