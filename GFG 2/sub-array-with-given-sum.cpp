#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, s;
        cin >> n >> s;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int si = 0, ei = -1;
        int sum = 0;
        while (si < n && ei < n)
        {
            if (sum < s)
            {
                ei++;
                sum += arr[ei];
            }
            else if (sum > s)
            {
                sum -= arr[si++];
            }
            else if (sum == s)
            {
                cout << si + 1 << " " << ei + 1 << endl;
                break;
            }
        }
        if (si == n || ei == n)
            cout << -1 << endl;
    }
    return 0;
}