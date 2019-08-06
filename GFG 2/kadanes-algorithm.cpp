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
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int maxsum = arr[0];
        int sumarr[n];
        sumarr[0] = arr[0];
        for (int i = 1; i < n; i++)
        {
            if (sumarr[i - 1] + arr[i] > arr[i])
                sumarr[i] = sumarr[i - 1] + arr[i];
            else
                sumarr[i] = arr[i];
        }
        for (int i = 0; i < n; i++)
        {
            if (sumarr[i] > maxsum)
                maxsum = sumarr[i];
        }
        cout << maxsum << endl;
    }
    return 0;
}