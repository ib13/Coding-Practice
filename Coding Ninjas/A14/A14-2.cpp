#include <iostream>
using namespace std;
#include <stack>

bool checkBalanced(char *exp)
{
    stack<char> s;
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '{' || exp[i] == '[' || exp[i] == '(')
            s.push(exp[i]);
        else if (exp[i] == '}' || exp[i] == ']' || exp[i] == ')')
        {
            if (s.empty())
                return false;
            if ((s.top() == '{' && exp[i] == '}') || (s.top() == '[' && exp[i] == ']') || (s.top() == '(' && exp[i] == ')'))
                s.pop();
            else
                return false;
        }
    }
    if (!s.empty())
        return false;
    return true;
}

int main()
{
    char input[100000];
    cin.getline(input, 100000);
    //    cin >> input;
    if (checkBalanced(input))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
}
