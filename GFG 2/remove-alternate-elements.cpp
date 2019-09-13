#include <bits/stdc++.h>
using namespace std;

int lastElement(int *arr, int n)
{
    int num = 1;
    while (n > 0)
    {
        n -= num;
        num = 2 * num;
    }
    return num / 2;
}

int lastElement1(int *arr, int n)
{
    bool flag = 0;
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        flag = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] != -1 && flag == 0)
            {
                arr[i] = -1;
                count++;
                flag = 1;
            }
            else if (arr[i] != -1 && flag == 1)
            {
                flag = 0;
            }
        }
        if (count == n - 1)
            break;
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return -1;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int *arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << lastElement(arr, n) << endl;
    }
    return 0;
}