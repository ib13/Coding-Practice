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
    A(int x)
    {
        cout << "Parametrized Constructor A " << x << endl;
    }
};

class B : virtual public A
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
    B(int x) : A(x)
    {
        cout << "Parametrized Constructor B " << x << endl;
    }
};

class C : virtual public A
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
    C(int x) : A(x)
    {
        cout << "Parametrized Constructor C " << x << endl;
    }
};

class D : public B, public C
{
public:
    void print()
    {
        cout << "Printing D";
    }
    D()
    {
        cout << "Default Constructor D" << endl;
    }
    D(int x) : A(x)
    {
        cout << "Parametrized Constructor D " << x << endl;
    }
};

int main()
{
    // D d;
    B b;
    // D d(5);
    // d.B::print();
    return 0;
}