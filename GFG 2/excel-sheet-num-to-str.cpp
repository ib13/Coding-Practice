#include <bits/stdc++.h>
using namespace std;
int findPow(int n, int index)
{
    int ans = 1;
    for (int i = 0; i < index; i++)
    {
        ans *= n;
    }
    return ans;
}

string findExcelRow(int n)
{
    int charLen = 0;
    int prevCharLen = 0;
    int remLen;
    int noOfChar;
    int index = 0;
    while (1)
    {
        int val = findPow(26, index + 1);
        charLen = prevCharLen + val;

        if (n <= charLen)
        {
            noOfChar = index + 1;
            remLen = n - prevCharLen - 1;
            break;
        }
        prevCharLen = charLen;
        index++;
    }
    int countArr[noOfChar] = {0};
    string output = "";
    while (remLen > 0)
    {
        char ch = (remLen) % 26 + 'A';
        output = ch + output;
        remLen = remLen / 26;
    }
    while (output.length() != noOfChar)
    {
        output = 'A' + output;
    }
    return output;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << findExcelRow(n) << endl;
    }
    return 0;
}