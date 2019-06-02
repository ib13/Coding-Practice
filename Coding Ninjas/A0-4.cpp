#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    cout << "*"
         << "\n";
    for (int i = 2; i <= n / 2 + 1; i++)
    {
        for (int j = 1; j <= 2 * i - 3; j++)
        {
            cout << " ";
        }
        for (int j = 1; j <= i; j++)
        {
            cout << "* ";
        }
        cout << "\n";
    }
    for (int i = n / 2; i >= 2; i--)
    {
        for (int j = 1; j <= 2 * i - 3; j++)
        {
            cout << " ";
        }
        for (int j = i; j >= 1; j--)
        {
            cout << "* ";
        }
        cout << "\n";
    }
    if (n != 1)
    {
        cout << "*";
    }

    return 0;
}