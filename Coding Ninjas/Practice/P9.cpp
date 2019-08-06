#include <bits/stdc++.h>
using namespace std;

class A
{
public:
    void print()
    {
        cout << "Printing A";
    }
    A()
    {
        cout << "Default Constructor A" << endl;
    }
};

class B : public A
{
public:
    void print()
    {
        cout << "Printing B";
    }
    B()
    {
        cout << "Default Constructor B" << endl;
    }
};

class C : public A
{
public:
    void print()
    {
        cout << "Printing C";
    }
    C()
    {
        cout << "Default Constructor C" << endl;
    }
};

int main()
{
    A a;
    cout << "---------------" << endl;
    B b;
    cout << "---------------" << endl;
    A *a1 = new A;
    cout << "---------------" << endl;
    A *a2;
    a2 = &b;
    return 0;
}