#include <bits/stdc++.h>
using namespace std;

int main()
{
    char c[] = "abc";
    cout << c << endl;
    char *p = &c[0];
    cout << c << endl;
    char c1 = 'a';
    char *p1 = &c1;
    cout << p1 << endl;
    return 0;
}