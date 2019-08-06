#include <bits/stdc++.h>
using namespace std;

bool parenthesisCheck(string str)
{
    stack<char> stk;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '{' || str[i] == '(' || str[i] == '[')
            stk.push(str[i]);
        else if (str[i] == '}' && stk.top() == '{')
            stk.pop();
        else if (str[i] == ']' && stk.top() == '[')
            stk.pop();
        else if (str[i] == ')' && stk.top() == '(')
            stk.pop();
        else
            return false;
    }
    if (stk.empty())
        return true;
    return false;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        if (parenthesisCheck(s))
            cout << "balanced" << endl;
        else
            cout << "not balanced" << endl;
    }
    return 0;
}