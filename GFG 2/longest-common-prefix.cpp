#include <bits/stdc++.h>
using namespace std;

string findLongestPrefix(string arr[], int n)
{
    int minlen = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int len = arr[i].length();
        minlen = min(minlen, len);
    }
    string str = "";
    for (int i = 0; i < minlen; i++)
    {
        char ch = arr[0][i];
        for (int j = 0; j < n; j++)
        {
            if (arr[j][i] != ch)
                return str;
        }
        str += ch;
    }

    return str;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << findLongestPrefix(arr, n) << endl;
    }
    return 0;
}