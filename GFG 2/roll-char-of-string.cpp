#include <bits/stdc++.h>
using namespace std;

string findRoll(string str, int roll[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < roll[i]; j++)
        {
            if (str[j] == 'z')
                str[j] = 'a';
            else
                str[j] += 1;
        }
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
        string str;
        cin >> str;
        int roll[n];
        for (int i = 0; i < n; i++)
        {
            cin >> roll[i];
        }
        cout << findRoll(str, roll, n) << endl;
    }
    return 0;
}