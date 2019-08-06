#include <bits/stdc++.h>
using namespace std;

void printAll(string s, int len, string str, int visited[])
{
    if (len == 0)
    {
        cout << str << " ";
        return;
    }
    for (int i = 0; i < s.length(); i++)
    {
        if (visited[i] == 0)
        {
            visited[i] = 1;
            printAll(s, len - 1, str + s[i], visited);
            visited[i] = 0;
        }
    }
}

void printPermutations(string s)
{
    int visited[s.length()] = {0};
    sort(s.begin(), s.end());
    printAll(s, s.length(), "", visited);
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        printPermutations(s);
    }
    return 0;
}