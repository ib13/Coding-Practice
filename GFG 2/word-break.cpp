#include <bits/stdc++.h>
using namespace std;

string findStr(string s, int si, int ei)
{
    return s.substr(si, ei - si + 1);
}

bool wordBreak(vector<string> dict, string word)
{
    int len = word.length();
    int dp[len][len];
    for (int j = 0; j < len; j++)
    {
        for (int i = len - 1; i >= 0; i--)
        {
            if (i <= j)
            {
                if (i == j)
                {
                    if (find(dict.begin(), dict.end(), findStr(word, i, j)) != dict.end())
                        dp[i][j] = 1;
                    else
                        dp[i][j] = 0;
                }
                else
                {
                    dp[i][j] = 0;
                    if (find(dict.begin(), dict.end(), findStr(word, i, j)) != dict.end())
                        dp[i][j] = 1;
                    else
                    {
                        for (int k = i; k < j; k++)
                        {
                            if (dp[i][k] == 1 && dp[k + 1][j] == 1)
                                dp[i][j] = 1;
                        }
                    }
                }
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    cout << "  ";
    for (int i = 0; i < len; i++)
    {
        cout << word[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < len; i++)
    {
        cout << word[i] << " ";
        for (int j = 0; j < len; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return dp[0][len - 1];
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> dict;
        for (int i = 0; i < n; i++)
        {
            string temp;
            cin >> temp;
            dict.push_back(temp);
        }
        string word;
        cin >> word;
        cout << wordBreak(dict, word) << endl;
    }

    return 0;
}