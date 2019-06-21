#include <iostream>
#include <limits.h>
using namespace std;

int minCountHelper(int n, int arr[])
{
    if (n == 1 || n == 0)
        return n;
    int minval = INT_MAX;
    for (int i = 1; i < n; i++)
    {
        if (n - i * i >= 0)
        {
            int count;
            if (arr[n - i * i] > 0)
                count = arr[n - i * i];
            else
            {
                count = minCountHelper(n - i * i, arr);
                arr[n - i * i] = count;
            }
            if (count < minval)
                minval = count;
        }
    }
    return 1 + minval;
}

int minCount(int n)
{
    int arr[n + 1] = {0};
    return minCountHelper(n, arr);
}

int main()
{

    int num;
    cin >> num;
    cout << minCount(num);
}
