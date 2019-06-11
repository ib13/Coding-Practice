#include <cmath>
#include <iostream>
#include <unordered_map>
using namespace std;

int makeAnagram(char str1[], char str2[])
{
    unordered_map<char, int> m1;
    unordered_map<char, int> m2;
    int len1 = 0, len2 = 0, finallen = 0, mindel = 0;
    for (int i = 0; str1[i] != '\0'; i++)
    {
        m1[str1[i]]++;
        len1++;
    }
    for (int i = 0; str2[i] != '\0'; i++)
    {
        m2[str2[i]]++;
        len2++;
    }
    for (int i = 0; str1[i] != '\0'; i++)
    {
        finallen += min(m1[str1[i]], m2[str1[i]]);
        m1[str1[i]] = 0;
    }
    mindel += (len1 - finallen) + (len2 - finallen);
    return mindel;
}

int main()
{
    char str1[10010], str2[10010];
    cin >> str1;
    cin >> str2;

    cout << makeAnagram(str1, str2) << endl;
}
