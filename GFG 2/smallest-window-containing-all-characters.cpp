#include <bits/stdc++.h>
using namespace std;

int smallestWindow(string str)
{
    int n = str.length();
    int i = 0, j = 0;
    int minWindow = n;
    bool charPresent[26] = {0};

    for (int k = 0; k < n; k++)
    {
        charPresent[str[k] - 'a'] = 1;
    }
    int currStatus[26] = {0};
    currStatus[str[0] - 'a'] = 1;
    while (i < n && j < n)
    {
        int flag = 1;
        for (int k = 0; k < 26; k++)
        {
            if (charPresent[k] == 1 && currStatus[k] == 0)
            {
                j++;
                if (j < n)
                {

                    currStatus[str[j] - 'a']++;
                }
                flag = 0;
            }
        }
        while (flag == 1 && i <= j)
        {
            minWindow = min(minWindow, j - i + 1);
            // cout << minWindow << " ";
            i++;
            currStatus[str[i - 1] - 'a']--;
            for (int k = 0; k < 26; k++)
            {
                if (charPresent[k] == 1 && currStatus[k] == 0)
                {
                    flag = 0;
                }
            }
        }
    }
    return minWindow;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        cout << smallestWindow(str) << endl;
    }
    return 0;
}