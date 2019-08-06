#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s1;
    string s2;
    cin >> s1 >> s2;
    unordered_map<char, int> m1;
    unordered_map<char, int> m2;
    int common_chars = 0;
    for (int i = 0; i < s1.length(); i++)
    {
        m1[s1[i]]++;
    }
    for (int i = 0; i < s2.length(); i++)
    {
        m2[s2[i]]++;
    }
    for (int i = 0; i < s1.length(); i++)
    {
        common_chars += min(m1[s1[i]], m2[s1[i]]);
        m1[s1[i]] = 0;
    }
    cout << s1.length() + s2.length() - 2 * common_chars;

    return 0;
}