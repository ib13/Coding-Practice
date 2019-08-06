#include <bits/stdc++.h>
using namespace std;

string removeDuplicates(string s)
{
    int curr = s.length();
    int prev;
    while (1)
    {
        if (curr == prev)
            break;
        curr = s.length();
        string finalStr = "";
        for (int i = 0; i < s.length(); i++)
        {
            int j = i;
            while (j + 1 < s.length() && s[j + 1] == s[i])
                j++;
            if (i == j)
                finalStr += s[i];
            i = j;
        }
        s = finalStr;
        prev = s.length();
    }
    return s;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        if (removeDuplicates(s).length() == 0)
            cout << " " << endl;
        else
        {
            cout << removeDuplicates(s) << endl;
        }
    }
    return 0;
}