#include <bits/stdc++.h>
using namespace std;

int getDigit(char c)
{
    if (c == 'I')
        return 1;
    else if (c == 'V')
        return 5;
    else if (c == 'X')
        return 10;
    else if (c == 'L')
        return 50;
    else if (c == 'C')
        return 100;
    else if (c == 'D')
        return 500;
    else if (c == 'M')
        return 1000;
    return -1;
}

int getRoman(string s)
{
    int len = s.length();
    int num = 0;
    for (int i = 0; i < len; i++)
    {
        if (i == len - 1)
        {
            int x = getDigit(s[i]);
            num += x;
        }
        else
        {
            int x = getDigit(s[i]);
            int y = getDigit(s[i + 1]);
            if (x >= y)
                num += x;
            else
                num -= x;
        }
    }
    return num;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        cout << getRoman(s) << endl;
    }
    return 0;
}