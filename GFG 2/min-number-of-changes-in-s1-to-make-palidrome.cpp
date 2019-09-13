#include <bits/stdc++.h>
using namespace std;

int findOperations(string s1)
{
    int n = s1.length();
    int count = 0;
    for (int i = 0; i < n / 2; i++)
    {
        if (s1[i] != s1[n - 1 - i])
            count++;
    }
    return count;
}

int makePalindrome(string s1, string s2)
{
    int minCount = INT_MAX;
    string temp;
    int l1 = s1.size();
    int l2 = s2.size();
    for (int i = 0; i < l1 - l2 + 1; i++)
    {
        temp = s1;
        int count = 0;
        for (int j = 0; j < l2; j++)
        {
            if (temp[i + j] != s2[j])
            {
                count++;
                temp[i + j] = s2[j];
            }
        }
        count += findOperations(temp);
        minCount = min(minCount, count);
    }
    return minCount;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;
        cout << makePalindrome(s1, s2) << endl;
    }
    return 0;
}