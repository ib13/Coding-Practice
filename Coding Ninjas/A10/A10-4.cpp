#include <iostream>
#include <cmath>
using namespace std;

#define modval (1000000007)
int binaryTreesOfHeightH(int h)
{
    // Formula n(h) = n(h-1)*n(h-1) + 2*n(h-2)*n(h-1)
    long long int arr[h + 1];

    // Base case
    arr[0] = 1;
    arr[1] = 1;

    for (int i = 2; i < h + 1; i++)
    {
        arr[i] = arr[i - 1] * arr[i - 1] + 2 * arr[i - 1] * arr[i - 2];
        arr[i] = arr[i] % modval;
    }
    return arr[h] % modval;
}

int main()
{
    int h;
    cin >> h;
    int ans = binaryTreesOfHeightH(h);
    ans = ans % ((int)(pow(10, 9)) + 7);
    cout << ans << endl;
}
