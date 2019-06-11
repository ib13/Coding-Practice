#include <iostream>
using namespace std;
#include <unordered_map>
#include <string>
#include <bits/stdc++.h>
char *findMinSubstringContainingString(char *large, char *small)
{
    unordered_map<char, int> ml;
    unordered_map<char, int> ms;
    string small_s(small);
    string large_s(large);
    int count = 0;
    int min_len = INT_MAX;
    int start_index = -1;
    for (int i = 0; i < small_s.length(); i++)
    {
        ms[small_s[i]]++;
    }
    int start = 0;
    for (int i = 0; i < large_s.length(); i++)
    {
        ml[large_s[i]]++;
        if (ms[large_s[i]] != 0 && ml[large_s[i]] <= ms[large_s[i]])
        {
            count++;
        }
        if (count == small_s.length())
        {
            while (ml[large_s[start]] > ms[large_s[start]] || ms[large_s[start]] == 0)
            {
                if (ml[large_s[start]] > ms[large_s[start]])
                {
                    ml[large_s[start]]--;
                }
                start++;
            }
            int len_window = i - start + 1;
            if (min_len > len_window)
            {
                min_len = len_window;
                start_index = start;
            }
        }
    }
    if (start_index == -1)
        return NULL;
    else
    {
        string s1 = large_s.substr(start_index, min_len);

        for (int i = 0; i < s1.length(); i++)
        {
            large[i] = s1[i];
        }
        large[s1.length()] = '\0';
        return large;
    }
}

int main()
{
    char S[1000000], T[1000];
    cin.getline(S, 1000000);
    cin.getline(T, 1000);
    char *ans = findMinSubstringContainingString(S, T);
    if (ans)
    {
        cout << ans << endl;
    }
    else
    {
        cout << "null" << endl;
    }
}
