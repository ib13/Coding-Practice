#include <bits/stdc++.h>
using namespace std;

int findPattern(string str, string pat)
{
    int slen = str.length();
    int plen = pat.length();
    for (int i = 0; i < slen - plen + 1; i++)
    {
        if (pat == str.substr(i, plen))
            return i;
    }
    return -1;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str, pat;
        cin >> str >> pat;
        cout << findPattern(str, pat) << endl;
    }
    return 0;
}