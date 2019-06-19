#include <iostream>
#include <string>
using namespace std;

void parenthesis(int n, int lp, int rp, string s)
{
    if (n == 0)
    {
        cout << s << endl;
        return;
    }
    if (lp == 0)
        parenthesis(n - 1, lp, rp - 1, s + ')');
    else if (lp < rp)
    {
        parenthesis(n - 1, lp - 1, rp, s + '(');
        parenthesis(n - 1, lp, rp - 1, s + ')');
    }
    else if (lp == rp)
        parenthesis(n - 1, lp - 1, rp, s + '(');
    else
        return;
}

void printWellFormedParanthesis(int n)
{
    parenthesis(2 * n, n, n, "");
}

int main()
{
    int n;
    cin >> n;
    printWellFormedParanthesis(n);
}