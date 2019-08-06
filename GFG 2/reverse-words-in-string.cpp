#include <bits/stdc++.h>
using namespace std;

void reverseString(string &s)
{
    vector<string> str;
    string temp = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '.')
        {
            str.push_back(temp);
            str.push_back(".");
            temp = "";
        }
        else
        {
            temp += s[i];
        }
    }
    str.push_back(temp);
    reverse(str.begin(), str.end());
    s = "";
    for (int i = 0; i < str.size(); i++)
    {
        s += str[i];
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        reverseString(s);
        cout << s << endl;
    }
    return 0;
}