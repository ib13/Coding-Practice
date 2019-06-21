#include <iostream>
#include <cstring>
using namespace std;
int editDistanceIter(string s1, string s2, int l1, int l2, int dp[][21])
{
    dp[0][0] = 0;
    for (int i = 1; i <= l1; i++)
    {
        dp[i][0] = dp[i - 1][0] + 1;
    }
    for (int i = 1; i <= l2; i++)
    {
        dp[0][i] = dp[0][i - 1] + 1;
    }
    for (int i = 1; i <= l1; i++)
    {
        for (int j = 1; j <= l2; j++)
        {
            if (s1[l1 - i] == s2[l2 - j])
                dp[i][j] = dp[i - 1][j - 1];
            else
            {
                dp[i][j] = 1 + min(min(dp[i][j - 1], dp[i - 1][j - 1]), dp[i - 1][j]);
            }
        }
    }
    return dp[l1][l2];
}

int editDistanceRec(string s1, string s2, int l1, int l2, int dp[][21])
{
    if (l1 == 0)
        return l2;
    else if (l2 == 0)
        return l1;
    if (s1[0] == s2[0])
    {
        if (dp[l1 - 1][l2 - 1] >= 0)
            return dp[l1 - 1][l2 - 1];
        else
        {
            int dist = editDistanceRec(s1.substr(1), s2.substr(1), l1 - 1, l2 - 1, dp);
            dp[l1 - 1][l2 - 1] = dist;
            return dist; //just move 1 step ahead in both
        }
    }

    else
    {
        int dist1, dist2, dist3;
        if (dp[l1 - 1][l2] >= 0)
            dist1 = 1 + dp[l1 - 1][l2];
        else
        {
            dist1 = 1 + editDistanceRec(s1.substr(1), s2, l1 - 1, l2, dp); //remove character in s1
            dp[l1 - 1][l2] = dist1 - 1;
        }
        if (dp[l1][l2 - 1] >= 0)
            dist2 = 1 + dp[l1][l2 - 1];
        else
        {
            dist2 = 1 + editDistanceRec(s1, s2.substr(1), l1, l2 - 1, dp); //remove character in s2
            dp[l1][l2 - 1] = dist2 - 1;
        }
        if (dp[l1 - 1][l2 - 1] >= 0)
            dist3 = 1 + dp[l1 - 1][l2 - 1];
        else
        {
            dist3 = 1 + editDistanceRec(s1.substr(1), s2.substr(1), l1 - 1, l2 - 1, dp); //edit character
            dp[l1 - 1][l2 - 1] = dist3 - 1;
        }
        return min(min(dist1, dist2), dist3);
    }
}

int editDistance(string s1, string s2)
{
    int l1 = s1.length();
    int l2 = s2.length();
    int dp[21][21];
    for (int i = 0; i < 21; i++)
    {
        for (int j = 0; j < 21; j++)
        {
            dp[i][j] = -1;
        }
    }

    // return editDistanceRec(s1, s2, l1, l2, dp);
    return editDistanceIter(s1, s2, l1, l2, dp);
}
int main()
{

    string s1;
    string s2;

    cin >> s1;
    cin >> s2;

    cout << editDistance(s1, s2) << endl;
}
