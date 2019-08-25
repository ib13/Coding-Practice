#include <bits/stdc++.h>
using namespace std;

void getPattern(string s)
{
    vector<int> res;
    int min_digit = 0;
    int pos_I = 0;
    if (s[0] == 'I')
    {
        res.push_back(1);
        res.push_back(2);
        min_digit = 3;
        pos_I = 1;
    }
    else
    {
        res.push_back(2);
        res.push_back(1);
        min_digit = 3;
    }
    for (int i = 1; i < s.length(); i++)
    {
        if (s[i] == 'I')
        {
            res.push_back(min_digit);
            min_digit++;
            pos_I = i + 1;
        }
        else
        {
            res.push_back(res[i]);
            for (int j = pos_I; j <= i; j++)
            {
                res[j]++;
            }
            min_digit++;
        }
    }
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        getPattern(s);
    }
    return 0;
}