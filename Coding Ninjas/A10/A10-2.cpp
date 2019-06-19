#include <iostream>
using namespace std;
#include <bits/stdc++.h>
#include <unordered_map>
#define mod (10e9 + 7)
unordered_map<string, int> m;
long long int getCodes(string input)
{
    if (input.length() <= 1)
    {
        return 1;
    }
    long long int c1;
    if (m[input.substr(1)] > 0)
        c1 = m[input.substr(1)];
    else
    {
        c1 = getCodes(input.substr(1));
        m[input.substr(1)] = c1;
    }

    long long int c2;
    long long int intval2 = (input[0] - '0') * 10 + input[1] - '0';
    if (intval2 <= 26)
    {
        if (m[input.substr(2)] > 0)
            c2 = m[input.substr(2)];
        else
        {
            c2 = getCodes(input.substr(2));
            m[input.substr(2)] = c2;
        }
    }
    else
        c2 = 0;

    return (c1 % ((long long int)mod) + c2 % ((long long int)mod)) % ((long long int)mod);
}

int main()
{
    string input = "junk";
    while (input != "0")
    {
        cin >> input;
        if (input != "0")
        {
            long long int count = getCodes(input);
            cout << count << endl;
        }
    }
    return 0;
}
