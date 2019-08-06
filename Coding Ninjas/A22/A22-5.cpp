#include <iostream>
using namespace std;

int turnOffFirstSetBit(int n)
{
    int m = 1;
    while (!(n & m))
        m <<= 1;
    int b = ~m;
    return n & b;
}

int main()
{
    int n;

    cin >> n;

    cout << turnOffFirstSetBit(n) << endl;

    return 0;
}
