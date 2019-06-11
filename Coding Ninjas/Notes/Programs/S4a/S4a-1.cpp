#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a = 5;
    cout << &a << endl; //address of a
    int *p = &a;
    cout << p << endl;  //address of a
    cout << *p << endl; //value a
    *p = 4;
    cout << a << endl;
    int *q = 0;
    *q = 5;
    cout << *q;
    return 0;
}