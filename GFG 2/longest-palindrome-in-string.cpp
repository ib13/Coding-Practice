#include <bits/stdc++.h>
using namespace std;

string evenPalindrome(string s, int index)
{
    int i = index;
    int j = index + 1;
    string palstr = "";
    while (i >= 0 && j < s.length() && s[i] == s[j])
    {
        palstr = s[i] + palstr + s[j];
        i--;
        j++;
    }
    return palstr;
}
string oddPalindrome(string s, int index1)
{
    int i = index1 - 1;
    int j = index1 + 1;
    string palstr = "";
    palstr += s[index1];
    while (i >= 0 && j < s.length() && s[i] == s[j])
    {
        palstr = s[i] + palstr + s[j];
        i--;
        j++;
    }
    return palstr;
}

string longestPalindrome(string s)
{
    string longestPal = "";
    for (int i = 0; i < s.length(); i++)
    {
        string evenPal = evenPalindrome(s, i);
        string oddPal = oddPalindrome(s, i);
        if (evenPal.length() > oddPal.length())
        {
            if (evenPal.length() > longestPal.length())
            {
                longestPal = evenPal;
            }
        }
        else
        {
            if (oddPal.length() > longestPal.length())
            {
                longestPal = oddPal;
            }
        }
    }
    return longestPal;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        cout << longestPalindrome(s) << endl;
    }
    return 0;
}