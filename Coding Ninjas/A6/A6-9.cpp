#include <iostream>
using namespace std;
#include <string>

void interleave(string s1, string s2, int i1, int i2, string s, int l1, int l2)
{
    // cout << s << endl;
    if (i1 == l1 && i2 == l2)
    {
        cout << s << endl;
        return;
    }
    if (i1 < l1 && i2 < l2)
    {
        interleave(s1.substr(1), s2, i1 + 1, i2, s + s1[0], l1, l2);
        interleave(s1, s2.substr(1), i1, i2 + 1, s + s2[0], l1, l2);
    }
    else if (i1 < l1)
    {
        interleave(s1.substr(1), s2, i1 + 1, i2, s + s1[0], l1, l2);
    }
    else if (i2 < l2)
    {
        interleave(s1, s2.substr(1), i1, i2 + 1, s + s2[0], l1, l2);
    }
}

void interleaving(char *first, char *second)
{
    string s1(first);
    string s2(second);
    interleave(first, second, 0, 0, "", s1.length(), s2.length());
}

int main()
{
    char *a = new char[1000];
    char *b = new char[1000];
    cin >> a;
    cin >> b;
    interleaving(a, b);
}
