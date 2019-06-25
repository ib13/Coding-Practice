#include <iostream>
using namespace std;
#include <stdint.h>
#include <unordered_map>

int64_t bytelandianHelper(int64_t n, unordered_map<int64_t, int64_t> &m)
{
    int64_t maxval;
    if (n >= 0 && n <= 3)
        return n;
    if (m.find(n) != m.end())
        return m[n];
    else
    {
        maxval = max(bytelandianHelper(n / 2, m) + bytelandianHelper(n / 3, m) + bytelandianHelper(n / 4, m), n);
        m[n] = maxval;
        return maxval;
    }
}

int64_t bytelandian(int64_t n)
{
    unordered_map<int64_t, int64_t> m;
    return bytelandianHelper(n, m);
}

int main()
{
    int64_t n;
    cin >> n;
    int64_t x = bytelandian(n);
    cout << x << endl;
}