#include <iostream>
using namespace std;
#include <stack>

int countBracketReversals(char input[])
{
    stack<char> s;
    int c1 = 0;
    int c2 = 0;
    for (int i = 0; input[i] != '\0'; i++)
    {
        if (input[i] == '{')
        {
            s.push('{');
        }
        if (input[i] == '}')
        {
            if (s.empty())
                c1++;
            else
                s.pop();
        }
    }
    while (!s.empty())
    {
        s.pop();
        c2++;
    }
    if ((c1 + c2) % 2 == 0)
    {
        if (c1 % 2 == 0)
            c1 = c1 / 2;
        else
            c1 = (c1 / 2) + 1;
        if (c2 % 2 == 0)
            c2 = c2 / 2;
        else
            c2 = (c2 / 2) + 1;
        return c1 + c2;
    }
    return -1;
}

int main()
{
    char input[10000];
    cin >> input;
    cout << countBracketReversals(input) << endl;
}