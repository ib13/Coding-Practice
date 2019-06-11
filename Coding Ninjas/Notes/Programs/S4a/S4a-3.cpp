#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << *a << endl;       //a[0]
    cout << *(a + 3) << endl; //a[3]
    cout << a << endl;        //print address of a
    cout << &a << endl;       //prints same address
    int *p = &a[0];
    cout << p << endl;
    cout << *p << endl;
    *p = 1;
    cout << a[0] << endl;
    return 0;
}