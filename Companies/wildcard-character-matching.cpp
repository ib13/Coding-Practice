#include <bits/stdc++.h>
using namespace std;

bool patternMatchRec(string str, string pat)
{
    if (str.length() == 0 && pat.length() == 0)
        return 1;
    if (str.length() == 0)
    {
        for (int i = 0; i < pat.length(); i++)
        {
            if (pat[i] != '*')
                return 0;
        }
        return 1;
    }
    if (pat[0] == '*')
        return patternMatchRec(str.substr(1), pat) || patternMatchRec(str, pat.substr(1));
    if (pat[0] == '?')
        return patternMatchRec(str.substr(1), pat.substr(1));
    else
    {
        if (str[0] != pat[0])
            return false;
        else
            return patternMatchRec(str.substr(1), pat.substr(1));
    }
}

bool patternMatchDP(string str, string pat)
{
    int dp[pat.length() + 1][str.length() + 1];
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str, pat;
        cin >> str >> pat;
        cout << patternMatch(str, pat) << endl;
    }
    return 0;
}