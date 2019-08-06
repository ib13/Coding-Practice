#include <bits/stdc++.h>
using namespace std;

bool anagrams(string s1, string s2)
{
    if (s1.length() != s2.length())
        return false;
    int c1[26] = {0};
    int c2[26] = {0};
    for (int i = 0; i < s1.length(); i++)
    {
        c1[s1[i] - 'a']++;
        c2[s2[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++)
    {
        if (c1[i] != c2[i])
            return false;
    }
    return true;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;
        if (anagrams(s1, s2))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}