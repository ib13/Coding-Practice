#include <bits/stdc++.h>
using namespace std;

bool isBitSet(int n, int k)
{
    int i = 1;
    i = i << k;
    if ((n & i) == 0)
        return 0;
    else
        return 1;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        if (isBitSet(n, k))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}