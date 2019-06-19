#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

#define modval (1000000007)

int countBST(int n)
{
    int arr[n + 1] = {0};
    arr[0] = 1;
    arr[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        int count = 0;
        for (int j = 1; j <= i; j++)
        {
            count = (count % modval + (arr[j - 1] % modval * arr[i - j] % modval) % modval) % modval;
        }
        arr[i] = count;
    }
    return arr[n];
}

int main()
{
    int n;
    cin >> n;
    cout << countBST(n);
    return 0;
}
