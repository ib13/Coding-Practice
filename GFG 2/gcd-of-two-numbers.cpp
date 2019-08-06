#include <bits/stdc++.h>
using namespace std;

int findGCD(int a, int b)
{
    if (b == 0)
        return a;
    findGCD(b, a % b);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        cout << findGCD(a, b) << endl;
    }
    return 0;
}