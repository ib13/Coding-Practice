#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i = 10;
    int *p = &i;
    int **pp = &p;
    cout << pp << endl;
    cout << &p << endl;
    cout << *pp << endl;
    cout << p << endl;
    cout << &i << endl;
    cout << i << endl;
    cout << *p << endl;
    cout << **pp << endl;
    return 0;
}