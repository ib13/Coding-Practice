/* C++ implementation to convert infix expression to postfix*/
// Note that here we use std::stack  for Stack operations
#include <iostream>
using namespace std;
#include <stack>

int prec(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

string infixToPostfix(string s)
{
    stack<char> st;
    st.push('N');
    int l = s.length();
    string ns;
    for (int i = 0; i < l; i++)
    {
        // If the scanned character is an operand, add it to output string.
        if (s[i] >= '0' && s[i] <= '9')
            ns += s[i];

        // If the scanned character is an ‘(‘, push it to the stack.
        else if (s[i] == '(')

            st.push('(');

        // If the scanned character is an ‘)’, pop and to output string from the stack
        // until an ‘(‘ is encountered.
        else if (s[i] == ')')
        {
            while (st.top() != 'N' && st.top() != '(')
            {
                char c = st.top();
                st.pop();
                ns += c;
            }
            if (st.top() == '(')
            {
                char c = st.top();
                st.pop();
            }
        }

        //If an operator is scanned
        else
        {
            while (st.top() != 'N' && prec(s[i]) <= prec(st.top()))
            {
                char c = st.top();
                st.pop();
                ns += c;
            }
            st.push(s[i]);
        }
    }
    //Pop all the remaining elements from the stack
    while (st.top() != 'N')
    {
        char c = st.top();
        st.pop();
        ns += c;
    }
    return ns;
}

int evalauteexp(string s)
{
    stack<int> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            st.push(s[i] - '0');
        }
        else
        {
            int ans;
            int num1 = st.top();
            st.pop();
            int num2 = st.top();
            st.pop();
            if (s[i] == '+')
                st.push(num2 + num1);
            if (s[i] == '-')
                st.push(num2 - num1);
            if (s[i] == '*')
                st.push(num2 * num1);
            if (s[i] == '/')
                st.push(num2 / num1);
        }
    }
    return st.top();
}

void evaluatePostfix(char exp[])
{
    string s(exp);
    string postexp = infixToPostfix(s);
    int ans = evalauteexp(postexp);
    cout << postexp << endl
         << ans;
}

//Driver program to test above functions
int main()
{
    char exp[1000];
    cin >> exp;
    evaluatePostfix(exp);
    return 0;
}
