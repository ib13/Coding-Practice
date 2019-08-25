#include <bits/stdc++.h>
using namespace std;

int flipBits(int n, int l, int r)
{
    int i = 1;
    i = i << (r - l + 1);
    i--;
    i = i << l - 1;
    return n ^ i;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, l, r;
        cin >> n >> l >> r;
        cout << flipBits(n, l, r) << endl;
    }
    return 0;
}