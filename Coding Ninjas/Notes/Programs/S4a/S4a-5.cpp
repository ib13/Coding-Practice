#include <bits/stdc++.h>
using namespace std;

void print(int *p)
{
    cout << *p << endl;
}
void arr(int *a)
{
    a[0] = 5;
}
void incP(int *p)
{
    p = p + 1;
}

void incV(int *p)
{
    (*p)++;
}

int main()
{
    int i = 10;
    int *p = &i;
    print(p);
    cout << p << endl;
    incP(p);
    cout << p << endl;
    cout << *p << endl;
    incV(p);
    cout << *p << endl;
    cout << i << endl;
    int a[] = {1, 2, 3, 4, 5};
    arr(a);
    cout << a[0] << endl;
    return 0;
}