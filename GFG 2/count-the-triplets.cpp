#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m[1000000] = {0};
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            m[arr[i]] = 1;
        }
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (m[arr[i] + arr[j]])
                    count++;
            }
        }
        if (count == 0)
            cout << -1 << endl;
        else
            cout << count << endl;
    }
    return 0;
}