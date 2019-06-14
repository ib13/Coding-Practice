#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int minCount(int n)
{
    if (n == 1 || n == 0)
        return n;
    int minval = INT_MAX;
    for (int i = 1; i < n; i++)
    {
        if (n - i * i >= 0)
        {
            int count = minCount(n - i * i);
            if (count < minval)
                minval = count;
        }
    }
    return 1 + minval;
}

int main()
{
    int num;
    cin >> num;
    cout << minCount(num);
}
