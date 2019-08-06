#include <bits/stdc++.h>
using namespace std;

int findZeros(int n)
{
    if (n <= 0)
        return 0;
    if (n % 10 == 0)
    {
        return 1 + findZeros(n / 10);
    }
    else
    {
        return findZeros(n / 10);
    }
}

int main()
{
    int n;
    cin >> n;
    cout << findZeros(n);
}