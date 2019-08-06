#include <iostream>
using namespace std;

int clearAllBits(int n, int i)
{
    int m = 1;
    m = m << i;
    m = m - 1;
    return n & m;
}

int main()
{
    int n, i;

    cin >> n >> i;

    cout << clearAllBits(n, i) << endl;

    return 0;
}
