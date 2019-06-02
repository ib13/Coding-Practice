#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n / 2; i++)
    {
        for (int j = (i - 1) * (2 * n) + 1; j <= (i - 1) * (2 * n) + n; j++)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
    if (n % 2 == 1)
    {
        for (int j = (n / 2) * (2 * n) + 1; j <= (n / 2) * (2 * n) + n; j++)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
    for (int i = n / 2; i >= 1; i--)
    {
        for (int j = (i - 1) * (2 * n) + n + 1; j <= (i - 1) * (2 * n) + n + n; j++)
        {
            cout << j << " ";
        }
        cout << "\n";
    }

    return 0;
}