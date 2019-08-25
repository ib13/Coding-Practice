#include <bits/stdc++.h>
using namespace std;

int firstSetBit(int n)
{
    int setBit = 1;
    while (n > 0)
    {
        if (n % 2 == 0)
        {
            setBit++;
            n = n >> 1;
        }
        else
        {
            return setBit;
        }
    }
    return 0;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << firstSetBit(n) << endl;
    }
    return 0;
}