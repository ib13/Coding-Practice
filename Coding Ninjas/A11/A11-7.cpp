#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int smallestSuperSequence(char str1[], int len1, char str2[], int len2)
{
    int dp[len1 + 1][len2 + 1];
    for (int i = 0; i < len1 + 1; i++)
    {
        dp[i][0] = i;
    }
    for (int i = 0; i < len2 + 1; i++)
    {
        dp[0][i] = i;
    }
    for (int i = 1; i < len1 + 1; i++)
    {
        for (int j = 1; j < len2 + 1; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[len1][len2];
}

int main()
{
    char str1[50], str2[50];
    cin >> str1;
    cin >> str2;
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int min_len = smallestSuperSequence(str1, len1, str2, len2);
    cout << min_len;
    return 0;
}
