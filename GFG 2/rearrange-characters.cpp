#include <bits/stdc++.h>
using namespace std;

bool canBeRearranged(string s)
{
    int n = s.length();
    int count[26] = {0};
    for (int i = 0; i < n; i++)
    {
        count[s[i] - 'a']++;
        if (count[s[i] - 'a'] > n / 2)
            return 0;
    }
    return 1;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        cout << canBeRearranged(s) << endl;
    }
    return 0;
}