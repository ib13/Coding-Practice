#include <bits/stdc++.h>
using namespace std;

int compare(string x, string y)
{
    string xy = x.append(y);
    string yx = y.append(x);
    if (x > y)
        return 1;
    else
        return 0;
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
        string str[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            str[i] = to_string(arr[i]);
        }
        int N = sizeof(str) / sizeof(str[0]);
        sort(str, str + N, compare);
        for (int i = 0; i < n; i++)
        {
            cout << str[i];
        }
        cout << endl;
    }
    return 0;
}