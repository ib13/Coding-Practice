#include <iostream>
using namespace std;

int turnOffIthBit(int n, int i)
{
    return n & ~(1 << i);
}

int main()
{
    int n, i;

    cin >> n >> i;

    cout << turnOffIthBit(n, i) << endl;

    return 0;
}
