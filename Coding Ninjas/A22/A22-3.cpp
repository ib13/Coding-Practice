#include <iostream>
using namespace std;

bool isPowerOf4(int n)
{
    return n != 0 && ((n & (n - 1)) == 0) && !(n & 0xAAAAAAAA);
}

int main()
{
    int n;

    cin >> n;

    if (isPowerOf4(n))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    return 0;
}
