#include <bits/stdc++.h>
using namespace std;

string numToStr(string keys)
{
    int n = keys.size();
    int index = 0;
    string res = "";
    vector<string> dialPad;
    dialPad.push_back(" 0");
    dialPad.push_back(",@1");
    dialPad.push_back("ABCabc2");
    dialPad.push_back("DEFdef3");
    dialPad.push_back("GHIghi4");
    dialPad.push_back("JKLjkl5");
    dialPad.push_back("MNOmno6");
    dialPad.push_back("PQRSpqrs7");
    dialPad.push_back("TUVtuv8");
    dialPad.push_back("WXYZwxyz9");
    for (int i = 0; i < n - 1; i++)
    {
        if (keys[i] == keys[i + 1])
        {
            index++;
        }
        else
        {
            if (keys[i] == '_')
            {
                index = 0;
            }
            else
            {
                int charToInt = keys[i] - '0';
                res += dialPad[charToInt][index % (dialPad[charToInt].size())];
                index = 0;
            }
        }
    }
    int charToInt = keys[n - 1] - '0';
    res += dialPad[charToInt][index % (dialPad[charToInt].size())];
    return res;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string keys;
        cin >> keys;
        cout << numToStr(keys) << endl;
    }
    return 0;
}