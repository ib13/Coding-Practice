#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string s = "Helo World";
    cout << s[2];
    s.erase(s.begin() + 2);
    cout << s[2];
    return 0;
}