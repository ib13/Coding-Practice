#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int *arr = new int[n];
        int count[3] = {0};
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            count[arr[i]]++;
        }
        for (int i = 0; i < count[0]; i++)
        {
            arr[i] = 0;
        }
        for (int i = count[0]; i < count[0] + count[1]; i++)
        {
            arr[i] = 1;
        }
        for (int i = count[0] + count[1]; i < count[0] + count[1] + count[2]; i++)
        {
            arr[i] = 2;
        }
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    return 0;
}