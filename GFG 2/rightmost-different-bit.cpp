#include <bits/stdc++.h>
using namespace std;

int differentBit(int n, int m)
{
    if (n == m)
        return -1;
    int bit = 1;
    int res = n ^ m;
    while (res > 0)
    {
        if (res % 2 == 1)
            return bit;
        else
        {
            bit++;
            res = res / 2;
        }
    }
    return bit;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        cout << differentBit(n, m) << endl;
    }
    return 0;
}