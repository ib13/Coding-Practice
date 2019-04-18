#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    cin >> tc;
    // tc = 1;
    while (tc--)
    {
        int n;
        string S;
        string X;
        cin >> n >> S >> X;
        int c = 0;
        long long int notPresent = 0;

        long long int totalSubstring = (n * (n + 1)) / 2;

        for (int i = 0; i < n; i++)
        {
            if (S[i] == X[0])
            {
                notPresent += ((c * (c + 1)) / 2);
                c = 0;
            }
            else
            {
                c++;
            }
        }

        notPresent += ((c * (c + 1)) / 2);
        long long int result = totalSubstring - notPresent;
        cout << result << "\n";
    }
    return 0;
}