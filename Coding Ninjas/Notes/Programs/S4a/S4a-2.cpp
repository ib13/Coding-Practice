#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a = 6;
    int *p = &a;
    cout << p << endl;
    p = p + 2;
    cout << p << endl;
    p++;
    cout << p << endl;
    p = p + a;
    cout << p << endl;
    if (p + 1 > p)
        cout << "True";
    return 0;
}