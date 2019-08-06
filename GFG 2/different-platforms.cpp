#include <bits/stdc++.h>
using namespace std;

int minPlatforms(int arrival[], int departure[], int n)
{
    sort(arrival, arrival + n);
    sort(departure, departure + n);
    int i = 0, j = 0;
    int plt = 0;
    int minplt = 0;
    while (i < n && j < n)
    {
        if (arrival[i] <= departure[j])
        {
            i++;
            plt++;
        }
        else
        {
            j++;
            plt--;
        }
        if (plt > minplt)
            minplt = plt;
    }
    return minplt;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arrival[n];
        int departure[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arrival[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> departure[i];
        }
        cout << minPlatforms(arrival, departure, n) << endl;
    }
    return 0;
}