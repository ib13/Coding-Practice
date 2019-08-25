#include <bits/stdc++.h>
using namespace std;

int totalDecodings(string code, int n, int index)
{
    if (index == n)
        return 1;
    if (code[0] == '1' && index < n - 1)
    {
        return totalDecodings(code.substr(1), n, index + 1) + totalDecodings(code.substr(2), n, index + 2);
    }

    else if (code[0] == '2' && index < n - 1 && code[1] >= '0' && code[1] <= '6')
        return totalDecodings(code.substr(1), n, index + 1) + totalDecodings(code.substr(2), n, index + 2);

    else if (code[0] == '0')
        return 0;
    return totalDecodings(code.substr(1), n, index + 1);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string code;
        cin >> code;
        cout << totalDecodings(code, n, 0) << endl;
    }
    return 0;
}