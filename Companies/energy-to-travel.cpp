#include <bits/stdc++.h>
using namespace std;

int minStopsHelper(int *dist, int *fuel, int n, int k, int index)
{
    if (index == n + 1)
        return 0;

    if (k < 0)
        return -1;

    int res1 = minStopsHelper(dist, fuel, n, k - dist[index + 1] + dist[index], index + 1);
    int res2 = minStopsHelper(dist, fuel, n, k + fuel[index] - dist[index + 1] + dist[index], index + 1);

    if (res1 == -1 && res2 == -1)
        return -1;
    else if (res1 == -1)
        return res2 + 1;
    else if (res2 == -1)
        return res1;
    else
        return min(res1, res2 + 1);
}

int minStops(int *dist, int *fuel, int n, int k)
{
    if (k < dist[0])
        return -1;
    return minStopsHelper(dist, fuel, n, k - dist[0], 0);
}

int main()
{
    int n;
    cin >> n;
    int *dist = new int[n + 1];
    for (int i = 0; i < n; i++)
    {
        cin >> dist[i];
    }
    int *fuel = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> fuel[i];
    }
    int d, k;
    cin >> d >> k;
    dist[n] = d;
    cout << minStops(dist, fuel, n, k);
    return 0;
}