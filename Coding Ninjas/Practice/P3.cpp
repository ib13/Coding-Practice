#include <bits/stdc++.h>
using namespace std;

void reverseString(string &s, int startIndex, int endIndex)
{
    int i = startIndex;
    int j = endIndex;
    while (i < j)
    {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }
}

int main()
{
    string s;
    getline(cin, s);
    int startIndex = 0, endIndex = -1;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            reverseString(s, startIndex, endIndex);
            startIndex = endIndex + 2;
            endIndex = endIndex + 1;
        }
        else
            endIndex++;
    }
    reverseString(s, startIndex, s.length() - 1);
    cout << s;

    return 0;
}