/* C++ implementation to convert infix expression to postfix*/
// Note that here we use std::stack  for Stack operations
#include <iostream>
using namespace std;
#include <stack>

void infixToPostfix(string s)
{
    std::stack<char> st;
    st.push('N');
    int l = s.length();
    string ns;
    for (int i = 0; i < l; i++)
    {
        // If the scanned character is an operand, add it to output string.
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
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

    cout << ns << endl;
}
void evaluatePostfix(char exp[])
{
}

//Driver program to test above functions
int main()
{
    char exp[1000];
    cin >> exp;
    evaluatePostfix(exp);
    return 0;
}
