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
        int arr[n - 1];
        for (int i = 0; i < n - 1; i++)
        {
            cin >> arr[i];
        }
        long sum = 0;
        for (int i = 0; i < n - 1; i++)
        {
            sum += arr[i];
        }

        long formulaSum = (n) * (n + 1) / 2;
        cout << formulaSum - sum << endl;
    }
    return 0;
}