#include <iostream>
using namespace std;

int returnFirstSetBit(int n)
{
    int m = 1;
    while (!(n & m))
        m = m << 1;

    return m;
}

int main()
{
    int n;

    cin >> n;

    cout << returnFirstSetBit(n) << endl;

    return 0;
}
